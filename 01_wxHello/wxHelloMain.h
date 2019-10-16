/***************************************************************
 * Name:      wxHelloMain.h
 * Purpose:   Defines Application Frame
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-16
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#ifndef WXHELLOMAIN_H
#define WXHELLOMAIN_H

//(*Headers(wxHelloFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class wxHelloFrame : public wxFrame
{
public:
    wxHelloFrame(wxWindow *parent, wxWindowID id = -1);
    virtual ~wxHelloFrame();

private:
    //(*Handlers(wxHelloFrame)
    void OnQuit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnClose(wxCloseEvent &event);
    void OnButtonHelloClick(wxCommandEvent &event);
    //*)

    //(*Identifiers(wxHelloFrame)
    static const long ID_BUTTON_HELLO;
    static const long ID_MENUITEM_QUIT;
    static const long ID_MENU_ABOUT;
    static const long ID_STATUSBAR;
    //*)

    //(*Declarations(wxHelloFrame)
    wxButton* ButtonHello;
    wxStatusBar* StatusBar;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // WXHELLOMAIN_H
