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
//*)

class wxWindowFrame: public wxFrame
{
    public:

        wxWindowFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxWindowFrame();

    private:

        //(*Handlers(wxWindowFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxWindowFrame)
        static const long ID_MENUITEM1;
        static const long ID_MENU_ABOUT;
        static const long ID_STATUSBAR;
        //*)

        //(*Declarations(wxWindowFrame)
        wxStatusBar* StatusBar;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXWINDOWMAIN_H
