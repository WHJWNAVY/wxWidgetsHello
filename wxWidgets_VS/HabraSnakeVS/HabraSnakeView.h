/////////////////////////////////////////////////////////////////////////////
// Name:        HabraSnakeView.h
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     10/11/2008 00:08:17
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008
// Licence:     Proprietary
/////////////////////////////////////////////////////////////////////////////

#ifndef _HABRA_SNAKE_VIEW_H
#define _HABRA_SNAKE_VIEW_H

#include <wx/wx.h>
#include <wx/docview.h>

class wxPointList;
class HabraSnakeDocument;

class HabraSnakeView : public wxView
{
	typedef bool (HabraSnakeDocument::* MovementFunction)(bool & targetFound);
	DECLARE_DYNAMIC_CLASS(HabraSnakeView)
	wxDirection m_CurrentDirection;
	wxTimer * m_GameTimer;
	void CreateGameTimer();
	wxRect GetGameFieldRectangle(const wxSize & size, int rectSize);
	void DrawGrid( wxDC* dc, wxRect &rect, int rectSize );
	void DrawSnake(wxDC * dc, wxRect & rect, int rectSize, const wxPointList & snake);
	void DrawTarget(wxDC * dc, wxRect & rect, int rectSize, const wxPoint & target);
	void DrawGameOverLabel(wxDC * dc, const wxRect & rect);
	void DrawScore(wxDC * dc, unsigned int score);
	void DoMove(HabraSnakeDocument * document, MovementFunction func, wxDirection direction);
	void RefreshScene();
public:
	HabraSnakeView();
	~HabraSnakeView();
	virtual void OnDraw(wxDC* dc);	
	virtual void OnUpdate(wxView *sender, wxObject *hint = (wxObject *) NULL);
	virtual bool OnClose(bool deleteWindow = true);
	DECLARE_EVENT_TABLE()
	void OnKeyDown(wxKeyEvent & event);
	void OnGameTimer(wxTimerEvent & event);
};

#endif
