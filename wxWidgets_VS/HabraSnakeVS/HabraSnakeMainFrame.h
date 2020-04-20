/////////////////////////////////////////////////////////////////////////////
// Name:        HabraSnakeMainFrame.h
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     30/11/2008 03:52:25
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008-2009
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _HABRASNAKEMAINFRAME_H_
#define _HABRASNAKEMAINFRAME_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/docview.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class HabraSnakeCanvas;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_HABRASNAKEMAINFRAME 10000
#define ID_FOREIGN 10007
#define SYMBOL_HABRASNAKEMAINFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_HABRASNAKEMAINFRAME_TITLE _("HabraSnake")
#define SYMBOL_HABRASNAKEMAINFRAME_IDNAME ID_HABRASNAKEMAINFRAME
#define SYMBOL_HABRASNAKEMAINFRAME_SIZE wxSize(400, 300)
#define SYMBOL_HABRASNAKEMAINFRAME_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * HabraSnakeMainFrame class declaration
 */

class HabraSnakeMainFrame: public wxDocParentFrame
{    
    DECLARE_CLASS( HabraSnakeMainFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    HabraSnakeMainFrame( wxDocManager *manager, wxFrame *parent, wxWindowID id = SYMBOL_HABRASNAKEMAINFRAME_IDNAME, const wxString& caption = SYMBOL_HABRASNAKEMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_HABRASNAKEMAINFRAME_POSITION, const wxSize& size = SYMBOL_HABRASNAKEMAINFRAME_SIZE, long style = SYMBOL_HABRASNAKEMAINFRAME_STYLE );

    bool Create( wxDocManager *manager, wxFrame *parent, wxWindowID id = SYMBOL_HABRASNAKEMAINFRAME_IDNAME, const wxString& caption = SYMBOL_HABRASNAKEMAINFRAME_TITLE, const wxPoint& pos = SYMBOL_HABRASNAKEMAINFRAME_POSITION, const wxSize& size = SYMBOL_HABRASNAKEMAINFRAME_SIZE, long style = SYMBOL_HABRASNAKEMAINFRAME_STYLE );

    /// Destructor
    ~HabraSnakeMainFrame();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin HabraSnakeMainFrame event handler declarations

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
    void OnABOUTClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
    void OnEXITClick( wxCommandEvent& event );

////@end HabraSnakeMainFrame event handler declarations

////@begin HabraSnakeMainFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end HabraSnakeMainFrame member function declarations

////@begin HabraSnakeMainFrame member variables
    HabraSnakeCanvas* m_Canvas;
////@end HabraSnakeMainFrame member variables
};

#endif
    // _HABRASNAKEMAINFRAME_H_
