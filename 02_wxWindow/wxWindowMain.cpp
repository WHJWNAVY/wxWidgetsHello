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
const long wxWindowFrame::ID_MENU_QUIT = wxNewId();
const long wxWindowFrame::ID_MENU_IMPORT_NETWORK = wxNewId();
const long wxWindowFrame::ID_MENU_IMPORT_LOCAL = wxNewId();
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

    //Quit菜单
    MenuItemQuit = new wxMenuItem(MenuFile, ID_MENU_QUIT, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemQuit);
    MenuFile->AppendSeparator();//分隔符
    //Import菜单
    wxMenu* MenuImport = new wxMenu();
    //Import子菜单
    wxMenuItem* MenuItemImportNetwork = new wxMenuItem(MenuImport, ID_MENU_IMPORT_NETWORK, _("Network\tAlt-F6"), _("Import file from network"), wxITEM_NORMAL);
    wxMenuItem* MenuItemImportLocal = new wxMenuItem(MenuImport, ID_MENU_IMPORT_LOCAL, _("Local\tAlt-F7"), _("Import file from local"), wxITEM_NORMAL);
    MenuImport->Append(MenuItemImportNetwork);
    MenuImport->Append(MenuItemImportLocal);
    MenuFile->AppendSubMenu(MenuImport, _("Import\tAlt-F5"));

    MenuBar->Append(MenuFile, _("&File"));

    //帮助菜单
    MenuHelp = new wxMenu();
    //关于菜单
    MenuItemAbout = new wxMenuItem(MenuHelp, ID_MENU_ABOUT, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    MenuHelp->Append(MenuItemAbout);

    //二级说明子菜单
    wxMenu* MenuRedme0 = new wxMenu();
    //三级说明子菜单
    MenuRedme0->Append(new wxMenuItem(MenuRedme0, wxID_ANY, _("Email0\tAlt-F7"), _("My Email 0"), wxITEM_NORMAL));
    MenuRedme0->Append(new wxMenuItem(MenuRedme0, wxID_ANY, _("Website0\tAlt-F8"), _("My Website 0"), wxITEM_NORMAL));

    //二级说明子菜单
    wxMenu* MenuRedme1 = new wxMenu();
    //三级说明子菜单
    MenuRedme1->Append(new wxMenuItem(MenuRedme1, wxID_ANY, _("Email1\tAlt-F7"), _("My Email 1"), wxITEM_NORMAL));
    MenuRedme1->Append(new wxMenuItem(MenuRedme1, wxID_ANY, _("Website1\tAlt-F8"), _("My Website 1"), wxITEM_NORMAL));

    //一级说明子菜单
    wxMenu* MenuRedme = new wxMenu();
    MenuRedme->AppendSubMenu(MenuRedme0, _("Redme0"));
    MenuRedme->AppendSubMenu(MenuRedme1, _("Redme1"));
    MenuHelp->AppendSeparator();//分隔符
    MenuHelp->AppendSubMenu(MenuRedme, _("Redme"));
    MenuBar->Append(MenuHelp, _("Help"));

    SetMenuBar(MenuBar);

    //状态栏
    StatusBar = new wxStatusBar(this, ID_STATUSBAR, 0, _T("ID_STATUSBAR"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);

    Center();

    Connect(ID_MENU_QUIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxWindowFrame::OnQuit);
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
