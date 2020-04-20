#include "HabraSnakeView.h"
#include "HabraSnakeMainFrame.h"
#include "HabraSnakeCanvas.h"
#include "HabraSnakeDocument.h"

IMPLEMENT_DYNAMIC_CLASS(HabraSnakeView, wxView)

BEGIN_EVENT_TABLE(HabraSnakeView, wxView)
EVT_KEY_DOWN(HabraSnakeView::OnKeyDown)
END_EVENT_TABLE()

HabraSnakeView::HabraSnakeView()
: m_CurrentDirection(wxLEFT)
{
	do 
	{
		HabraSnakeMainFrame * mainFrame = 
			wxDynamicCast(wxTheApp->GetTopWindow(), HabraSnakeMainFrame);
		if(!mainFrame) break;
		HabraSnakeCanvas * canvas = mainFrame->m_Canvas;
		SetFrame(canvas);
		canvas->SetView(this);
		canvas->Refresh();
		CreateGameTimer();
	} 
	while (false);
}

HabraSnakeView::~HabraSnakeView()
{
	wxDELETE(m_GameTimer);
}

void HabraSnakeView::CreateGameTimer()
{
	long gameTimerID = wxNewId();
	m_GameTimer = new wxTimer(this, (int)gameTimerID);
	Connect(gameTimerID, wxEVT_TIMER, wxTimerEventHandler(HabraSnakeView::OnGameTimer));
	m_GameTimer->Start(300);
}

void HabraSnakeView::OnDraw(wxDC* dc)
{
	int rectSize = dc->GetSize().GetWidth()/HabraSnakeDocument::GetGameFieldSize().GetWidth();
	rectSize = wxMin(rectSize, 
		(int)dc->GetSize().GetHeight()/HabraSnakeDocument::GetGameFieldSize().GetHeight());
	wxRect rect = GetGameFieldRectangle(dc->GetSize(), rectSize);
	DrawGrid(dc, rect, rectSize);
	do 
	{
		HabraSnakeDocument * document = wxDynamicCast(GetDocument(), HabraSnakeDocument);
		if(!document) break;
		DrawScore(dc, document->GetScore());
		if(!document->IsGameOver())
		{
			DrawSnake(dc, rect, rectSize, document->GetSnake());
			DrawTarget(dc, rect, rectSize, document->GetTarget());
		}
		else
		{
			DrawGameOverLabel(dc, rect);
		}
	} 
	while (false);
}

void HabraSnakeView::DrawScore(wxDC * dc, unsigned int score)
{
	int w(0), h(0);
	dc->GetSize(&w, &h);
	wxString scoreLabel = _("SCORE");
	wxString scoreValue = wxString::Format(wxT("%u"), score);
	wxSize textSize = dc->GetTextExtent(scoreLabel);
	wxRect scoreRect(wxPoint(0,0), textSize);
	textSize = dc->GetTextExtent(scoreValue);
	scoreRect.SetWidth(wxMax(scoreRect.GetWidth(), textSize.GetWidth()));
	scoreRect.SetHeight((int)(scoreRect.GetHeight() + (double)6 / (double)5 * 
		(double)textSize.GetHeight()));
	scoreRect.Inflate(5, 5);
#if defined(__WXWINCE__)
	int distance = 5;
#else
	int distance = 10;
#endif
	scoreRect.SetPosition(wxPoint(w - scoreRect.GetWidth() - distance, distance));
	dc->SetPen(*wxBLACK_PEN);
	dc->SetBrush(*wxWHITE_BRUSH);
	dc->DrawRectangle(scoreRect);
	scoreRect.Deflate(5, 5);
	dc->DrawLabel(scoreLabel, scoreRect, wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL);
	dc->DrawLabel(scoreValue, scoreRect, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL);
}

void HabraSnakeView::DrawGameOverLabel(wxDC * dc, const wxRect & rect)
{
	wxFont font = dc->GetFont();
	font.SetPointSize(12);
	dc->SetFont(font);
	dc->SetTextForeground(wxColour(127,0,0));
	wxString label = _("GAME OVER");
	wxSize textSize = dc->GetTextExtent(label);
	dc->SetBackground(wxBrush(wxColour(200,200,200)));
	dc->SetPen(*wxBLACK_PEN);
	wxRect labelRect(rect.GetLeft() + (rect.GetWidth()-textSize.GetWidth())/2 - 10,
		rect.GetTop() + (rect.GetHeight()-textSize.GetHeight())/2 - 10,
		textSize.GetWidth()+20, textSize.GetHeight()+20);
	dc->DrawRectangle(labelRect);
	dc->DrawLabel(label, labelRect, wxALIGN_CENTER);
}

void HabraSnakeView::DrawSnake(wxDC * dc, wxRect & rect, int rectSize, const wxPointList & snake)
{
	dc->SetPen(*wxTRANSPARENT_PEN);
	dc->SetBrush(wxBrush(wxColour(0,0,127)));
	wxRect cell(0,0,rectSize, rectSize);
	for(wxPointList::Node * node = snake.GetFirst(); node; node = node->GetNext())
	{
		wxPoint * point = node->GetData();
		if(!point) continue;
		cell.SetPosition(wxPoint(
			rect.GetLeft()+point->x*rectSize, 
			rect.GetTop()+point->y*rectSize));
		dc->DrawRectangle(cell);
	}
}

void HabraSnakeView::DrawTarget(wxDC * dc, wxRect & rect, int rectSize, const wxPoint & target)
{
	dc->SetPen(*wxTRANSPARENT_PEN);
	dc->SetBrush(wxBrush(wxColour(0,150,50)));
	wxRect cell(rect.GetLeft()+target.x*rectSize,rect.GetTop()+target.y*rectSize,rectSize, rectSize);
	dc->DrawRectangle(cell);
}

wxRect HabraSnakeView::GetGameFieldRectangle(const wxSize & size, int rectSize)
{
	wxRect rect(0, 0, HabraSnakeDocument::GetGameFieldSize().GetWidth()*rectSize+1,
		HabraSnakeDocument::GetGameFieldSize().GetHeight()*rectSize+1);
	rect.Offset((size.GetWidth()-rect.GetWidth())/2,
		(size.GetHeight()-rect.GetHeight())/2);
	return rect;
}

void HabraSnakeView::DrawGrid( wxDC* dc, wxRect &rect, int rectSize )
{
	dc->DrawRectangle(rect);
	dc->SetPen(wxPen(wxColour(192,192,192)));
	for(int i = 1; i < HabraSnakeDocument::GetGameFieldSize().GetWidth(); i++)
	{
		dc->DrawLine(rect.GetLeft()+i*rectSize, rect.GetTop()+1,
			rect.GetLeft()+i*rectSize, rect.GetBottom());
	}
	for(int i = 1; i < HabraSnakeDocument::GetGameFieldSize().GetHeight(); i++)
	{
		dc->DrawLine(rect.GetLeft()+1, rect.GetTop()+i*rectSize,
			rect.GetRight(), rect.GetTop()+i*rectSize);
	}
}

void HabraSnakeView::OnUpdate(wxView *sender, wxObject *hint)
{
	GetFrame()->Refresh();
}

bool HabraSnakeView::OnClose(bool deleteWindow)
{
	if (!GetDocument()->Close())
	{
		return false;
	}
	HabraSnakeCanvas * frame = wxDynamicCast(GetFrame(), HabraSnakeCanvas);
	if(frame)
	{
		frame->SetView(NULL);
		frame->Refresh();
	}
	SetFrame(NULL);
	Activate(false);
	return true;
}

void HabraSnakeView::DoMove(HabraSnakeDocument * document, 
							HabraSnakeView::MovementFunction func, 
							wxDirection direction)
{
	bool targetFound(false);
	if((document->*func)(targetFound))
	{
		m_CurrentDirection = direction;
		if(targetFound)
		{
			int interval = 350 - 15 * wxMin(20, document->GetSnake().GetCount()-3);
			m_GameTimer->Start(interval);
			wxLogTrace(wxTraceMask(), _("Timer interval = %i"), interval);
		}
	}
}

void HabraSnakeView::OnKeyDown(wxKeyEvent & event)
{
	do 
	{
		HabraSnakeDocument * document = wxDynamicCast(GetDocument(), HabraSnakeDocument);
		if(!document) break;
		if(document->IsGameOver()) break;
		switch(event.GetKeyCode())
		{
		case WXK_LEFT:
		case WXK_NUMPAD_LEFT:
			if(m_CurrentDirection == wxLEFT) return;
			DoMove(document, &HabraSnakeDocument::MoveLeft, wxLEFT);
			break;
		case WXK_RIGHT:
		case WXK_NUMPAD_RIGHT:
			if(m_CurrentDirection == wxRIGHT) return;
			DoMove(document, &HabraSnakeDocument::MoveRight, wxRIGHT);
			break;
		case WXK_UP:
		case WXK_NUMPAD_UP:
			if(m_CurrentDirection == wxUP) return;
			DoMove(document, &HabraSnakeDocument::MoveUp, wxUP);
			break;
		case WXK_DOWN:
		case WXK_NUMPAD_DOWN:
			if(m_CurrentDirection == wxDOWN) return;
			DoMove(document, &HabraSnakeDocument::MoveDown, wxDOWN);
			break;
		default:
			event.Skip();
			return;
		}
	} 
	while (false);
	RefreshScene();
}

void HabraSnakeView::RefreshScene()
{
	HabraSnakeCanvas * frame = wxDynamicCast(GetFrame(), HabraSnakeCanvas);
	if(frame)
	{
		frame->RefreshScene();
		frame->Refresh();
	}
}

void HabraSnakeView::OnGameTimer(wxTimerEvent & event)
{
	do 
	{
		HabraSnakeDocument * document = wxDynamicCast(GetDocument(), HabraSnakeDocument);
		if(!document) break;
		MovementFunction func = NULL;
		switch(m_CurrentDirection)
		{
		case wxLEFT:
			func = &HabraSnakeDocument::MoveLeft;
			break;
		case wxUP:
			func = &HabraSnakeDocument::MoveUp;
			break;
		case wxRIGHT:
			func = &HabraSnakeDocument::MoveRight;
			break;
		case wxDOWN:
			func = &HabraSnakeDocument::MoveDown;
			break;
		default:
			return;
		}
		if(func)
		{
			DoMove(document, func, m_CurrentDirection);
			RefreshScene();
		}
	} 
	while (false);
}
