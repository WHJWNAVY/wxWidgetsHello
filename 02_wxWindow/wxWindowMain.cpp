/***************************************************************
 * Name:      wxWindowMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-16
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#include "wxWindowMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxWindowFrame)
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

//(*IdInit(wxWindowFrame)
const long wxWindowFrame::ID_MENUITEM1 = wxNewId();
const long wxWindowFrame::ID_MENU_ABOUT = wxNewId();
const long wxWindowFrame::ID_STATUSBAR = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxWindowFrame,wxFrame)
    //(*EventTable(wxWindowFrame)
    //*)
END_EVENT_TABLE()

wxWindowFrame::wxWindowFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxWindowFrame)
    wxMenu* MenuFile;
    wxMenu* MenuHelp;
    wxMenuBar* MenuBar;
    wxMenuItem* MenuItemAbout;
    wxMenuItem* MenuItemQuit;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxNO_BORDER|wxCLIP_CHILDREN, _T("wxID_ANY"));
    SetClientSize(wxSize(640,640));
    MenuBar = new wxMenuBar();
    MenuFile = new wxMenu();
    MenuItemQuit = new wxMenuItem(MenuFile, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemQuit);
    MenuBar->Append(MenuFile, _("&File"));
    MenuHelp = new wxMenu();
    MenuItemAbout = new wxMenuItem(MenuHelp, ID_MENU_ABOUT, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    MenuHelp->Append(MenuItemAbout);
    MenuBar->Append(MenuHelp, _("Help"));
    SetMenuBar(MenuBar);
    StatusBar = new wxStatusBar(this, ID_STATUSBAR, 0, _T("ID_STATUSBAR"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);
    Center();

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxWindowFrame::OnQuit);
    Connect(ID_MENU_ABOUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxWindowFrame::OnAbout);
    //*)
}

wxWindowFrame::~wxWindowFrame()
{
    //(*Destroy(wxWindowFrame)
    //*)
}

void wxWindowFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxWindowFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
