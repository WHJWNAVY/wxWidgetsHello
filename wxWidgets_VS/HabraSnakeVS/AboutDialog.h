/////////////////////////////////////////////////////////////////////////////
// Name:        AboutDialog.h
// Purpose:
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by:
// Created:     30/11/2008 03:54:02
// RCS-ID:
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008-2009
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _ABOUTDIALOG_H_
#define _ABOUTDIALOG_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/hyperlink.h"
#include "wx/statline.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_ABOUTDIALOG 10002
#define ID_DEVELOPERS_TEXTCTRL 10003
#define ID_HOMEPAGE_HYPERLINK 10004
#define ID_SUPPORT_HYPERLINK 10005
#define SYMBOL_ABOUTDIALOG_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_ABOUTDIALOG_TITLE _("About HabraSnake...")
#define SYMBOL_ABOUTDIALOG_IDNAME ID_ABOUTDIALOG
#define SYMBOL_ABOUTDIALOG_SIZE wxSize(400, 300)
#define SYMBOL_ABOUTDIALOG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * AboutDialog class declaration
 */

class AboutDialog: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( AboutDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    AboutDialog();
    AboutDialog( wxWindow* parent, wxWindowID id = SYMBOL_ABOUTDIALOG_IDNAME, const wxString& caption = SYMBOL_ABOUTDIALOG_TITLE, const wxPoint& pos = SYMBOL_ABOUTDIALOG_POSITION, const wxSize& size = SYMBOL_ABOUTDIALOG_SIZE, long style = SYMBOL_ABOUTDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ABOUTDIALOG_IDNAME, const wxString& caption = SYMBOL_ABOUTDIALOG_TITLE, const wxPoint& pos = SYMBOL_ABOUTDIALOG_POSITION, const wxSize& size = SYMBOL_ABOUTDIALOG_SIZE, long style = SYMBOL_ABOUTDIALOG_STYLE );

    /// Destructor
    ~AboutDialog();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin AboutDialog event handler declarations

    /// wxEVT_COMMAND_HYPERLINK event handler for ID_HOMEPAGE_HYPERLINK
    void OnHyperLinkClicked( wxHyperlinkEvent& event );

////@end AboutDialog event handler declarations

////@begin AboutDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end AboutDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin AboutDialog member variables
////@end AboutDialog member variables
};

#endif
    // _ABOUTDIALOG_H_
