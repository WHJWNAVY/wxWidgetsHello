/***************************************************************
 * Name:      wxHelloMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-16
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#include "wxHelloMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxHelloFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f,
    long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows"); // _T("xxx") 和 wxT("xxx") 功能相同, 为了兼容unicode
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

//(*IdInit(wxHelloFrame)
const long wxHelloFrame::ID_BUTTON_HELLO = wxNewId();
const long wxHelloFrame::ID_MENUITEM_QUIT = wxNewId();
const long wxHelloFrame::ID_MENU_ABOUT = wxNewId();
const long wxHelloFrame::ID_STATUSBAR = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxHelloFrame, wxFrame)
//(*EventTable(wxHelloFrame) 事件表可以代替Connect函数
    EVT_MENU(ID_MENUITEM_QUIT, wxHelloFrame::OnQuit)
    EVT_MENU(ID_MENU_ABOUT, wxHelloFrame::OnAbout)
    EVT_BUTTON(ID_BUTTON_HELLO, wxHelloFrame::OnButtonHelloClick)
//*)
END_EVENT_TABLE()

wxHelloFrame::wxHelloFrame(wxWindow *parent, wxWindowID id)
{
    //(*Initialize(wxHelloFrame)
    wxMenu *MenuFile;
    wxMenu *MenuHelp;
    wxMenuBar *MenuBar;
    wxMenuItem *MenuItemAbout;
    wxMenuItem *MenuItemQuit;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    ButtonHello = new wxButton(this, ID_BUTTON_HELLO, _("wxHelloWorld"), wxPoint(136, 288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_HELLO"));

    MenuBar = new wxMenuBar();
    MenuFile = new wxMenu();
    MenuItemQuit = new wxMenuItem(MenuFile, ID_MENUITEM_QUIT, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemQuit);
    MenuBar->Append(MenuFile, _("&File"));

    MenuHelp = new wxMenu();
    MenuItemAbout = new wxMenuItem(MenuHelp, ID_MENU_ABOUT, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    MenuHelp->Append(MenuItemAbout);
    MenuBar->Append(MenuHelp, _("Help"));

    SetMenuBar(MenuBar);

    StatusBar = new wxStatusBar(this, ID_STATUSBAR, 0, _T("ID_STATUSBAR"));
    int __wxStatusBarWidths_1[1] = {-1};
    int __wxStatusBarStyles_1[1] = {wxSB_NORMAL};
    StatusBar->SetFieldsCount(1, __wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(1, __wxStatusBarStyles_1);
    SetStatusBar(StatusBar);

#if 0
    Connect(ID_BUTTON_HELLO, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&wxHelloFrame::OnButtonHelloClick);
    Connect(ID_MENUITEM_QUIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&wxHelloFrame::OnQuit);
    Connect(ID_MENU_ABOUT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&wxHelloFrame::OnAbout);
#endif
    //*)
}

wxHelloFrame::~wxHelloFrame()
{
    //(*Destroy(wxHelloFrame)
    //*)
}

void wxHelloFrame::OnQuit(wxCommandEvent &event)
{
    Close();
}

void wxHelloFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxHelloFrame::OnButtonHelloClick(wxCommandEvent &event)
{
    wxString msgs = _("Hello World!");
    wxMessageBox(msgs, _("wxHelloWorld")); // _("xxx") 为了把字符串翻译成指定的语言
}
