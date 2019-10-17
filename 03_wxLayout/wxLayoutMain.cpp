/***************************************************************
 * Name:      wxLayoutMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-17
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#include "wxLayoutMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxLayoutFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxLayoutFrame)
const long wxLayoutFrame::ID_BUTTON1 = wxNewId();
const long wxLayoutFrame::ID_BUTTON2 = wxNewId();
const long wxLayoutFrame::ID_BUTTON4 = wxNewId();
const long wxLayoutFrame::ID_BUTTON3 = wxNewId();
const long wxLayoutFrame::ID_BUTTON5 = wxNewId();
const long wxLayoutFrame::ID_BUTTON6 = wxNewId();
const long wxLayoutFrame::ID_MENUITEM1 = wxNewId();
const long wxLayoutFrame::ID_MENU_ITEM_ABOUT = wxNewId();
const long wxLayoutFrame::ID_STATUSBAR = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxLayoutFrame,wxFrame)
    //(*EventTable(wxLayoutFrame)
    //*)
END_EVENT_TABLE()

wxLayoutFrame::wxLayoutFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxLayoutFrame)
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* MenuFile;
    wxMenu* MenuHelp;
    wxMenuBar* MenuBar;
    wxMenuItem* MenuItemAbout;
    wxMenuItem* MenuItemQuit;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(2);
    FlexGridSizer1->AddGrowableRow(1);
    Button1 = new wxButton(this, ID_BUTTON1, _("Label(0,0)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Label(0,1)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer1->Add(Button2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Label(0,2)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer1->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Label(1,0)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer1->Add(Button3, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button5 = new wxButton(this, ID_BUTTON5, _("Label(1,1)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    FlexGridSizer1->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("Label(1,2)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    FlexGridSizer1->Add(Button6, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar = new wxMenuBar();
    MenuFile = new wxMenu();
    MenuItemQuit = new wxMenuItem(MenuFile, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemQuit);
    MenuBar->Append(MenuFile, _("&File"));
    MenuHelp = new wxMenu();
    MenuItemAbout = new wxMenuItem(MenuHelp, ID_MENU_ITEM_ABOUT, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    MenuHelp->Append(MenuItemAbout);
    MenuBar->Append(MenuHelp, _("Help"));
    SetMenuBar(MenuBar);
    StatusBar = new wxStatusBar(this, ID_STATUSBAR, 0, _T("ID_STATUSBAR"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    Center();

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxLayoutFrame::OnQuit);
    Connect(ID_MENU_ITEM_ABOUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxLayoutFrame::OnAbout);
    //*)
}

wxLayoutFrame::~wxLayoutFrame()
{
    //(*Destroy(wxLayoutFrame)
    //*)
}

void wxLayoutFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxLayoutFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxLayoutFrame::OnButton2Click(wxCommandEvent& event)
{
}
