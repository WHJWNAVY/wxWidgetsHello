/////////////////////////////////////////////////////////////////////////////
// Name:        AboutDialog.cpp
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     30/11/2008 03:54:02
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

#include "AboutDialog.h"

////@begin XPM images
////@end XPM images


/*!
 * AboutDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( AboutDialog, wxDialog )


/*!
 * AboutDialog event table definition
 */

BEGIN_EVENT_TABLE( AboutDialog, wxDialog )

////@begin AboutDialog event table entries
    EVT_HYPERLINK( ID_HOMEPAGE_HYPERLINK, AboutDialog::OnHyperLinkClicked )

    EVT_HYPERLINK( ID_SUPPORT_HYPERLINK, AboutDialog::OnHyperLinkClicked )

////@end AboutDialog event table entries

END_EVENT_TABLE()


/*!
 * AboutDialog constructors
 */

AboutDialog::AboutDialog()
{
    Init();
}

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * AboutDialog creator
 */

bool AboutDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin AboutDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end AboutDialog creation
    return true;
}


/*!
 * AboutDialog destructor
 */

AboutDialog::~AboutDialog()
{
////@begin AboutDialog destruction
////@end AboutDialog destruction
}


/*!
 * Member initialisation
 */

void AboutDialog::Init()
{
////@begin AboutDialog member initialisation
////@end AboutDialog member initialisation
}


/*!
 * Control creation for AboutDialog
 */

void AboutDialog::CreateControls()
{    
////@begin AboutDialog content construction
    AboutDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("HabraSnake"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText3->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("v1.0"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxStaticBox* itemStaticBoxSizer5Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Developers"));
    wxStaticBoxSizer* itemStaticBoxSizer5 = new wxStaticBoxSizer(itemStaticBoxSizer5Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer5, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    wxTextCtrl* itemTextCtrl6 = new wxTextCtrl( itemDialog1, ID_DEVELOPERS_TEXTCTRL, _("Volodymir (T-Rex) Tryapichko,\nBabloid.com"), wxDefaultPosition, wxSize(200, -1), wxTE_MULTILINE|wxTE_READONLY );
    itemStaticBoxSizer5->Add(itemTextCtrl6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxHyperlinkCtrl* itemHyperlinkCtrl7 = new wxHyperlinkCtrl( itemDialog1, ID_HOMEPAGE_HYPERLINK, _("HabraSnake homepage"), _T("http://babloid.com/habrasnake"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
    itemBoxSizer2->Add(itemHyperlinkCtrl7, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxHyperlinkCtrl* itemHyperlinkCtrl8 = new wxHyperlinkCtrl( itemDialog1, ID_SUPPORT_HYPERLINK, _("Support"), _T("mailto:support@babloid.com"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
    itemBoxSizer2->Add(itemHyperlinkCtrl8, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxStaticLine* itemStaticLine9 = new wxStaticLine( itemDialog1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer2->Add(itemStaticLine9, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    wxButton* itemButton10 = new wxButton( itemDialog1, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemButton10, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end AboutDialog content construction
}


/*!
 * Should we show tooltips?
 */

bool AboutDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap AboutDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin AboutDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end AboutDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon AboutDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin AboutDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end AboutDialog icon retrieval
}


/*!
 * wxEVT_COMMAND_HYPERLINK event handler for ID_HOMEPAGE_HYPERLINK
 */

void AboutDialog::OnHyperLinkClicked( wxHyperlinkEvent& event )
{
#if defined(__WXMSW__) || defined(__WXWINCE__)
	SHELLEXECUTEINFO info;
	ZeroMemory(&info, sizeof(SHELLEXECUTEINFO));
	info.cbSize = sizeof(SHELLEXECUTEINFO);
	info.lpFile = event.GetURL().GetData();
	info.lpVerb = L"open";
	info.nShow = SW_SHOW;
	::ShellExecuteEx(&info);
#else
	event.Skip();
#endif
}

