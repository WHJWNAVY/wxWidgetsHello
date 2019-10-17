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
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/image.h>
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
const long wxWindowFrame::ID_MENU_OPEN_LOCAL = wxNewId();
const long wxWindowFrame::ID_MENU_OPEN_NET163 = wxNewId();
const long wxWindowFrame::ID_MENU_OPEN_NETALI_TAOBAO = wxNewId();
const long wxWindowFrame::ID_MENU_OPEN_NETALI_TMALL = wxNewId();
const long wxWindowFrame::ID_MENU_OPEN_NETALIYUN = wxNewId();
const long wxWindowFrame::ID_MENU_OPEN_NET = wxNewId();
const long wxWindowFrame::ID_MENU_OPEN = wxNewId();
const long wxWindowFrame::ID_MENU_LINENUMBER = wxNewId();
const long wxWindowFrame::ID_MENU_LINEBREAK = wxNewId();
const long wxWindowFrame::ID_MENU_CODING_ASCII = wxNewId();
const long wxWindowFrame::ID_MENU_CODING_UTF8 = wxNewId();
const long wxWindowFrame::ID_MENU_CODING = wxNewId();
const long wxWindowFrame::ID_MENU_ABOUT = wxNewId();
const long wxWindowFrame::ID_STATUSBAR = wxNewId();
const long wxWindowFrame::ID_TOOLBAR_OPEN = wxNewId();
const long wxWindowFrame::ID_TOOLBAR = wxNewId();
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
    MenuItemOpen = new wxMenu();
    MenuItemLocal = new wxMenuItem(MenuItemOpen, ID_MENU_OPEN_LOCAL, _("Local\tAlt-F6"), _("Open file or project from local"), wxITEM_NORMAL);
    MenuItemOpen->Append(MenuItemLocal);
    MenuItemNetwork = new wxMenu();
    MenuItemNeteasy = new wxMenuItem(MenuItemNetwork, ID_MENU_OPEN_NET163, _("Neteasy\tAlt-F7"), _("Open file or project from 163.com"), wxITEM_NORMAL);
    MenuItemNetwork->Append(MenuItemNeteasy);
    MenuItemAliyun = new wxMenu();
    MenuItemTaobao = new wxMenuItem(MenuItemAliyun, ID_MENU_OPEN_NETALI_TAOBAO, _("Taobao\tAlt-F8"), _("Open file or project from taobao.com"), wxITEM_NORMAL);
    MenuItemAliyun->Append(MenuItemTaobao);
    MenuItemTmall = new wxMenuItem(MenuItemAliyun, ID_MENU_OPEN_NETALI_TMALL, _("Tmall\tAlt-F9"), _("Open file or project from tmall.com"), wxITEM_NORMAL);
    MenuItemAliyun->Append(MenuItemTmall);
    MenuItemNetwork->Append(ID_MENU_OPEN_NETALIYUN, _("Aliyun"), MenuItemAliyun, _("Open file or project from aliyun"));
    MenuItemOpen->Append(ID_MENU_OPEN_NET, _("Network"), MenuItemNetwork, _("Open file or project from network"));
    MenuFile->Append(ID_MENU_OPEN, _("Open"), MenuItemOpen, _("Open file or project"));
    MenuFile->AppendSeparator();
    MenuItem1 = new wxMenuItem(MenuFile, ID_MENU_LINENUMBER, _("LineNumber"), _("Show line number"), wxITEM_CHECK);
    MenuFile->Append(MenuItem1);
    MenuItem2 = new wxMenuItem(MenuFile, ID_MENU_LINEBREAK, _("AutoBreak"), _("Auto line break"), wxITEM_CHECK);
    MenuFile->Append(MenuItem2);
    MenuFile->AppendSeparator();
    MenuItem3 = new wxMenu();
    MenuItem4 = new wxMenuItem(MenuItem3, ID_MENU_CODING_ASCII, _("ASCII"), _("File encode with ascii"), wxITEM_RADIO);
    MenuItem3->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(MenuItem3, ID_MENU_CODING_UTF8, _("UTF8"), _("File encode with utf-8"), wxITEM_RADIO);
    MenuItem3->Append(MenuItem5);
    MenuFile->Append(ID_MENU_CODING, _("Coding"), MenuItem3, _("File encoding"));
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
    ToolBar = new wxToolBar(this, ID_TOOLBAR, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR"));
    ToolBarItemOpen = ToolBar->AddTool(ID_TOOLBAR_OPEN, _("Open"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),wxART_TOOLBAR), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW_DIR")),wxART_TOOLBAR), wxITEM_NORMAL, _("Open file"), _("Open file"));
    ToolBar->Realize();
    SetToolBar(ToolBar);
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
