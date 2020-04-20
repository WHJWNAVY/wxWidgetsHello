/////////////////////////////////////////////////////////////////////////////
// Name:        HabraSnakeCanvas.cpp
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     04/12/2008 03:02:02
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008-2009
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "HabraSnakeCanvas.h"
#include <wx/mstream.h>

////@begin XPM images
////@end XPM images
#include "background_jpg.h"


/*!
 * HabraSnakeCanvas type definition
 */

IMPLEMENT_DYNAMIC_CLASS( HabraSnakeCanvas, wxWindow )


/*!
 * HabraSnakeCanvas event table definition
 */

BEGIN_EVENT_TABLE( HabraSnakeCanvas, wxWindow )

////@begin HabraSnakeCanvas event table entries
    EVT_SIZE( HabraSnakeCanvas::OnSize )
    EVT_PAINT( HabraSnakeCanvas::OnPaint )
    EVT_ERASE_BACKGROUND( HabraSnakeCanvas::OnEraseBackground )
    EVT_LEFT_DOWN( HabraSnakeCanvas::OnLeftDown )
    EVT_KEY_DOWN( HabraSnakeCanvas::OnKeyDown )

////@end HabraSnakeCanvas event table entries

END_EVENT_TABLE()


/*!
 * HabraSnakeCanvas constructors
 */

HabraSnakeCanvas::HabraSnakeCanvas()
{
    Init();
}

HabraSnakeCanvas::HabraSnakeCanvas(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
{
    Init();
    Create(parent, id, pos, size, style);
}


/*!
 * HabraSnakeCanvas creator
 */

bool HabraSnakeCanvas::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
{
////@begin HabraSnakeCanvas creation
    wxWindow::Create(parent, id, pos, size, style);
    CreateControls();
////@end HabraSnakeCanvas creation
    return true;
}


/*!
 * HabraSnakeCanvas destructor
 */

HabraSnakeCanvas::~HabraSnakeCanvas()
{
////@begin HabraSnakeCanvas destruction
////@end HabraSnakeCanvas destruction
}


/*!
 * Member initialisation
 */

void HabraSnakeCanvas::Init()
{
////@begin HabraSnakeCanvas member initialisation
    m_View = NULL;
////@end HabraSnakeCanvas member initialisation
}


/*!
 * Control creation for HabraSnakeCanvas
 */

void HabraSnakeCanvas::CreateControls()
{    
////@begin HabraSnakeCanvas content construction
////@end HabraSnakeCanvas content construction
	wxMemoryInputStream in(background_jpg, sizeof(background_jpg));
	m_BackgroundBitmap = wxBitmap(wxImage(in));
#if defined(__WXWINCE__)
	wxFont font = GetFont();
	font.SetPointSize(8);
	SetFont(font);
#endif
}

/*!
 * wxEVT_PAINT event handler for ID_HABRASNAKECANVAS
 */

void HabraSnakeCanvas::OnPaint( wxPaintEvent& event )
{
    wxPaintDC dc(this);
	if(m_DoubleBufferDC.IsOk())
	{
		dc.Blit(0, 0, m_DoubleBufferDC.GetSize().GetWidth(), 
			m_DoubleBufferDC.GetSize().GetHeight(), &m_DoubleBufferDC, 0, 0);
	}
	else
	{
		dc.SetBackground(wxBrush(GetBackgroundColour()));
		dc.Clear();
	}
}

void HabraSnakeCanvas::DrawBackground( wxDC &dc )
{
	if(m_BackgroundBitmap.IsOk())
	{
		int w(0), h(0);
		dc.GetSize(&w, &h);
		for(int x = 0; x < w; x += m_BackgroundBitmap.GetWidth())
		{
			for(int y = 0; y < h; y += m_BackgroundBitmap.GetHeight())
			{
				dc.DrawBitmap(m_BackgroundBitmap, x, y);
			}
		}
	}
}

/*!
 * wxEVT_ERASE_BACKGROUND event handler for ID_HABRASNAKECANVAS
 */

void HabraSnakeCanvas::OnEraseBackground( wxEraseEvent& event )
{
}

/*!
 * Get bitmap resources
 */

wxBitmap HabraSnakeCanvas::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin HabraSnakeCanvas bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end HabraSnakeCanvas bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon HabraSnakeCanvas::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin HabraSnakeCanvas icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end HabraSnakeCanvas icon retrieval
}


/*!
 * wxEVT_LEFT_DOWN event handler for ID_HABRASNAKECANVAS
 */

void HabraSnakeCanvas::OnLeftDown( wxMouseEvent& event )
{
	SetFocus();
}


/*!
 * wxEVT_KEY_DOWN event handler for ID_HABRASNAKECANVAS
 */

void HabraSnakeCanvas::OnKeyDown( wxKeyEvent& event )
{
	if(m_View)
	{
		m_View->ProcessEvent(event);
	}
}

void HabraSnakeCanvas::RefreshScene()
{
	if(m_View)
	{
		DrawBackground(m_DoubleBufferDC);
		m_DoubleBufferDC.SetFont(GetFont());
		m_DoubleBufferDC.SetBrush(wxBrush(GetBackgroundColour()));
		m_DoubleBufferDC.SetPen(*wxBLACK_PEN);
		m_View->OnDraw(&m_DoubleBufferDC);
	}
}


/*!
 * wxEVT_SIZE event handler for ID_HABRASNAKECANVAS
 */

void HabraSnakeCanvas::OnSize( wxSizeEvent& event )
{
	m_DoubleBufferDC.SelectObject(wxNullBitmap);
	m_DoubleBufferBitmap = wxBitmap(event.GetSize().GetWidth(), event.GetSize().GetHeight());
	m_DoubleBufferDC.SelectObject(m_DoubleBufferBitmap);
	RefreshScene();
	Refresh();
}

