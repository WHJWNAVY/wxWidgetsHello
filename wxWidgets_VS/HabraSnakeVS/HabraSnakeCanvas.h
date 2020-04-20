/////////////////////////////////////////////////////////////////////////////
// Name:        HabraSnakeCanvas.h
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     04/12/2008 03:02:02
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008-2009
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _HABRASNAKECANVAS_H_
#define _HABRASNAKECANVAS_H_


/*!
 * Includes
 */

////@begin includes
////@end includes
#include <wx/docview.h>

/*!
 * Forward declarations
 */

////@begin forward declarations
class HabraSnakeCanvas;
////@end forward declarations
class HabraSnakeView;

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_HABRASNAKECANVAS 10001
#define SYMBOL_HABRASNAKECANVAS_STYLE wxSIMPLE_BORDER
#define SYMBOL_HABRASNAKECANVAS_IDNAME ID_HABRASNAKECANVAS
#define SYMBOL_HABRASNAKECANVAS_SIZE wxSize(100, 100)
#define SYMBOL_HABRASNAKECANVAS_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * HabraSnakeCanvas class declaration
 */

class HabraSnakeCanvas: public wxWindow
{    
    DECLARE_DYNAMIC_CLASS( HabraSnakeCanvas )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    HabraSnakeCanvas();
    HabraSnakeCanvas(wxWindow* parent, wxWindowID id = ID_HABRASNAKECANVAS, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(100, 100), long style = wxSIMPLE_BORDER);

    /// Creation
    bool Create(wxWindow* parent, wxWindowID id = ID_HABRASNAKECANVAS, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(100, 100), long style = wxSIMPLE_BORDER);

    /// Destructor
    ~HabraSnakeCanvas();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin HabraSnakeCanvas event handler declarations

    /// wxEVT_SIZE event handler for ID_HABRASNAKECANVAS
    void OnSize( wxSizeEvent& event );

    /// wxEVT_PAINT event handler for ID_HABRASNAKECANVAS
    void OnPaint( wxPaintEvent& event );

    /// wxEVT_ERASE_BACKGROUND event handler for ID_HABRASNAKECANVAS
    void OnEraseBackground( wxEraseEvent& event );

    /// wxEVT_LEFT_DOWN event handler for ID_HABRASNAKECANVAS
    void OnLeftDown( wxMouseEvent& event );

    /// wxEVT_KEY_DOWN event handler for ID_HABRASNAKECANVAS
    void OnKeyDown( wxKeyEvent& event );

////@end HabraSnakeCanvas event handler declarations

////@begin HabraSnakeCanvas member function declarations

    wxView * GetView() const { return m_View ; }
    void SetView(wxView * value) { m_View = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end HabraSnakeCanvas member function declarations
	void DrawBackground( wxDC &dc );
	void RefreshScene();

////@begin HabraSnakeCanvas member variables
    wxView * m_View;
////@end HabraSnakeCanvas member variables
private:
	wxBitmap m_BackgroundBitmap;
	wxBitmap m_DoubleBufferBitmap;
	wxMemoryDC m_DoubleBufferDC;
private:
};

#endif
    // _HABRASNAKECANVAS_H_
