/////////////////////////////////////////////////////////////////////////////
// Name:        HabraSnakeMainFrame.cpp
// Purpose:
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by:
// Created:     30/11/2008 03:52:25
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

#include "HabraSnakeMainFrame.h"
#include "HabraSnakeCanvas.h"
#include "AboutDialog.h"

////@begin XPM images
////@end XPM images


/*!
 * HabraSnakeMainFrame type definition
 */

IMPLEMENT_CLASS( HabraSnakeMainFrame, wxDocParentFrame )


/*!
 * HabraSnakeMainFrame event table definition
 */

BEGIN_EVENT_TABLE( HabraSnakeMainFrame, wxDocParentFrame )

////@begin HabraSnakeMainFrame event table entries
    EVT_MENU( wxID_ABOUT, HabraSnakeMainFrame::OnABOUTClick )

    EVT_MENU( wxID_EXIT, HabraSnakeMainFrame::OnEXITClick )

////@end HabraSnakeMainFrame event table entries

END_EVENT_TABLE()


/*!
 * HabraSnakeMainFrame constructors
 */

HabraSnakeMainFrame::HabraSnakeMainFrame( wxDocManager *manager, wxFrame *parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
    : wxDocParentFrame( manager, parent, id, caption, pos, size, style )
{
    Init();
    Create( manager, parent, id, caption, pos, size, style );
}


/*!
 * HabraSnakeMainFrame creator
 */

bool HabraSnakeMainFrame::Create( wxDocManager *manager, wxFrame *parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin HabraSnakeMainFrame creation
    SetParent(parent);
    CreateControls();
    Centre();
////@end HabraSnakeMainFrame creation
    return true;
}


/*!
 * HabraSnakeMainFrame destructor
 */

HabraSnakeMainFrame::~HabraSnakeMainFrame()
{
////@begin HabraSnakeMainFrame destruction
////@end HabraSnakeMainFrame destruction
}


/*!
 * Member initialisation
 */

void HabraSnakeMainFrame::Init()
{
////@begin HabraSnakeMainFrame member initialisation
    m_Canvas = NULL;
////@end HabraSnakeMainFrame member initialisation
}


/*!
 * Control creation for HabraSnakeMainFrame
 */

void HabraSnakeMainFrame::CreateControls()
{
////@begin HabraSnakeMainFrame content construction
    HabraSnakeMainFrame* itemDocParentFrame1 = this;

    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* itemMenu3 = new wxMenu;
    itemMenu3->Append(wxID_NEW, _("New\tCtrl+N"), _T(""), wxITEM_NORMAL);
    itemMenu3->AppendSeparator();
    itemMenu3->Append(wxID_ABOUT, _("About..."), _T(""), wxITEM_NORMAL);
    itemMenu3->AppendSeparator();
    itemMenu3->Append(wxID_EXIT, _("Exit\tAlt+F4"), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu3, _("File"));
    itemDocParentFrame1->SetMenuBar(menuBar);

    m_Canvas = new HabraSnakeCanvas( itemDocParentFrame1, ID_FOREIGN, wxDefaultPosition, wxSize(100, 100), wxNO_BORDER );

////@end HabraSnakeMainFrame content construction
#if defined(__WXMSW__)
	SetIcon(wxIcon(wxT("wxICON_AAA")));
#endif
#if !defined(__WXWINCE__)
	SetSize(350, 450);
	SetMinSize(GetSize());
#endif
	m_Canvas->RefreshScene();
	wxCommandEvent event(wxEVT_COMMAND_MENU_SELECTED, wxID_NEW);
	ProcessEvent(event);
	m_Canvas->SetFocus();
}

/*!
 * Get bitmap resources
 */

wxBitmap HabraSnakeMainFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin HabraSnakeMainFrame bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end HabraSnakeMainFrame bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon HabraSnakeMainFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin HabraSnakeMainFrame icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end HabraSnakeMainFrame icon retrieval
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
 */

void HabraSnakeMainFrame::OnABOUTClick( wxCommandEvent& event )
{
    AboutDialog * dlg = new AboutDialog(this);
    dlg->ShowModal();
    dlg->Destroy();
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
 */

void HabraSnakeMainFrame::OnEXITClick( wxCommandEvent& event )
{
    Close();
}

