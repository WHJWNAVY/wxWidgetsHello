/***************************************************************
 * Name:      wxWindowMain.h
 * Purpose:   Defines Application Frame
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-16
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#ifndef WXWINDOWMAIN_H
#define WXWINDOWMAIN_H

 //(*Headers(wxWindowFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
//*)

class wxWindowFrame : public wxFrame
{
public:

    wxWindowFrame(wxWindow* parent, wxWindowID id = -1);
    virtual ~wxWindowFrame();

private:

    //(*Handlers(wxWindowFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnRightUp(wxMouseEvent& event);
    //*)

    //(*Identifiers(wxWindowFrame)
    static const long ID_MENUITEM1;
    static const long ID_MENU_OPEN_LOCAL;
    static const long ID_MENU_OPEN_NET163;
    static const long ID_MENU_OPEN_NETALI_TAOBAO;
    static const long ID_MENU_OPEN_NETALI_TMALL;
    static const long ID_MENU_OPEN_NETALIYUN;
    static const long ID_MENU_OPEN_NET;
    static const long ID_MENU_OPEN;
    static const long ID_MENU_LINENUMBER;
    static const long ID_MENU_LINEBREAK;
    static const long ID_MENU_CODING_ASCII;
    static const long ID_MENU_CODING_UTF8;
    static const long ID_MENU_CODING;
    static const long ID_MENU_ABOUT;
    static const long ID_STATUSBAR;
    static const long ID_TOOLBAR_OPEN;
    static const long ID_TOOLBAR;
    static const long ID_MENU_POP_ADD;
    static const long ID_MENU_POP_DELETE;
    //*)

    //(*Declarations(wxWindowFrame)
    wxMenu MenuPopUp;
    wxMenu* MenuItemAliyun;
    wxMenu* MenuItemCoding;
    wxMenu* MenuItemNetwork;
    wxMenu* MenuItemOpen;
    wxMenuItem* MenuItemAscii;
    wxMenuItem* MenuItemAutoBreak;
    wxMenuItem* MenuItemLineNumber;
    wxMenuItem* MenuItemLocal;
    wxMenuItem* MenuItemNeteasy;
    wxMenuItem* MenuItemPopAdd;
    wxMenuItem* MenuItemPopDelete;
    wxMenuItem* MenuItemTaobao;
    wxMenuItem* MenuItemTmall;
    wxMenuItem* MenuItemUtf8;
    wxStatusBar* StatusBar;
    wxToolBar* ToolBar;
    wxToolBarToolBase* ToolBarItemOpen;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // WXWINDOWMAIN_H
