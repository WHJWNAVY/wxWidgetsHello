#include "HabraSnakeDocument.h"
#include <wx/listimpl.cpp>

WX_DEFINE_LIST(wxPointList)

IMPLEMENT_DYNAMIC_CLASS(HabraSnakeDocument, wxDocument)

wxSize HabraSnakeDocument::GameFieldSize = wxSize(25, 50);

HabraSnakeDocument::HabraSnakeDocument()
{
	srand(time(NULL));
	m_GameOver = false;
	m_Score = 0;
	CreateNewTarget();
	InitSnake();
}

void HabraSnakeDocument::InitSnake()
{
	m_Snake.DeleteContents(true);
	m_Snake.Append(new wxPoint(15,25));
	m_Snake.Append(new wxPoint(16,25));
	m_Snake.Append(new wxPoint(17,25));
}

wxSize HabraSnakeDocument::GetGameFieldSize()
{
	return HabraSnakeDocument::GameFieldSize;
}

const wxPointList & HabraSnakeDocument::GetSnake() const
{
	return m_Snake;
}

bool HabraSnakeDocument::IsGameOver()
{
	return m_GameOver;
}

unsigned int HabraSnakeDocument::GetScore()
{
	return m_Score;
}

const wxPoint & HabraSnakeDocument::GetTarget() const
{
	return m_Target;
}

void HabraSnakeDocument::CreateNewTarget()
{
	m_Target.x = rand() % GameFieldSize.GetWidth();
	m_Target.y = rand() % GameFieldSize.GetHeight();
}

bool HabraSnakeDocument::IsSnakeDead()
{
	do 
	{
		wxPointList::Node * firstNode = m_Snake.GetFirst();
		if(!firstNode) break;
		wxPoint * head = firstNode->GetData();
		if(!head) break;
		for(wxPointList::Node * node = firstNode->GetNext(); node; node = node->GetNext())
		{
			wxPoint * point = node->GetData();
			if(*head == *point) return true;
		}
	} 
	while (false);
	return false;
}

bool HabraSnakeDocument::CanMoveTo(wxPoint & pos)
{
	do 
	{
		wxPointList::Node * second = m_Snake.Item(1);
		if(!second) break;
		wxPoint * secondPoint = second->GetData();
		if(!secondPoint) break;
		if((secondPoint->x != pos.x) || (secondPoint->y != pos.y)) break;
		return false;
	} 
	while (false);
	return true;
}

void HabraSnakeDocument::ProcessNewPoint(wxPoint * newPoint, bool & targetFound)
{
	if(*newPoint == m_Target)
	{
		m_Score += 10;
		targetFound = true;
		CreateNewTarget();
	}
	else
	{
		targetFound = false;
		m_Snake.DeleteNode(m_Snake.GetLast());
	}
	m_Snake.Insert((size_t)0, newPoint);
}

bool HabraSnakeDocument::MoveLeft(bool & targetFound)
{
	do
	{
		if(m_GameOver) break;
		wxPointList::Node * node = m_Snake.GetFirst();
		if(!node) break;
		wxPoint * point = node->GetData();
		if(!point) break;
		wxPoint * newPoint = new wxPoint(
			(point->x-1 < 0) ? HabraSnakeDocument::GameFieldSize.GetWidth()-1 : point->x-1,
			point->y);
		if(!CanMoveTo(*newPoint))
		{
			wxDELETE(newPoint);
			break;
		}
		ProcessNewPoint(newPoint, targetFound);
		if(IsSnakeDead()) m_GameOver = true;
		return true;
	}
	while(false);
	return false;
}

bool HabraSnakeDocument::MoveUp(bool & targetFound)
{
	do
	{
		if(m_GameOver) break;
		wxPointList::Node * node = m_Snake.GetFirst();
		if(!node) break;
		wxPoint * point = node->GetData();
		if(!point) break;
		wxPoint * newPoint = new wxPoint(
			point->x,
			(point->y-1 < 0) ? HabraSnakeDocument::GameFieldSize.GetHeight()-1 : point->y-1);
		if(!CanMoveTo(*newPoint))
		{
			wxDELETE(newPoint);
			break;
		}
		ProcessNewPoint(newPoint, targetFound);
		if(IsSnakeDead()) m_GameOver = true;
		return true;
	}
	while(false);
	return false;
}

bool HabraSnakeDocument::MoveRight(bool & targetFound)
{
	do
	{
		if(m_GameOver) break;
		wxPointList::Node * node = m_Snake.GetFirst();
		if(!node) break;
		wxPoint * point = node->GetData();
		if(!point) break;
		wxPoint * newPoint = new wxPoint(
			(point->x+1 > HabraSnakeDocument::GameFieldSize.GetWidth()-1) ? 0 : point->x+1,
			point->y);
		if(!CanMoveTo(*newPoint))
		{
			wxDELETE(newPoint);
			break;
		}
		ProcessNewPoint(newPoint, targetFound);
		if(IsSnakeDead()) m_GameOver = true;
		return true;
	}
	while(false);
	return false;
}

bool HabraSnakeDocument::MoveDown(bool & targetFound)
{
	do
	{
		if(m_GameOver) break;
		wxPointList::Node * node = m_Snake.GetFirst();
		if(!node) break;
		wxPoint * point = node->GetData();
		if(!point) break;
		wxPoint * newPoint = new wxPoint(
			point->x,
			(point->y+1 > HabraSnakeDocument::GameFieldSize.GetHeight()-1) ? 0 : point->y+1);
		if(!CanMoveTo(*newPoint))
		{
			wxDELETE(newPoint);
			break;
		}
		ProcessNewPoint(newPoint, targetFound);
		if(IsSnakeDead()) m_GameOver = true;
		return true;
	}
	while(false);
	return false;
}
