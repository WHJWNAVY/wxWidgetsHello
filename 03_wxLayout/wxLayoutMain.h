/***************************************************************
 * Name:      wxLayoutMain.h
 * Purpose:   Defines Application Frame
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-17
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#ifndef WXLAYOUTMAIN_H
#define WXLAYOUTMAIN_H

//(*Headers(wxLayoutFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class wxLayoutFrame: public wxFrame
{
    public:

        wxLayoutFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxLayoutFrame();

    private:

        //(*Handlers(wxLayoutFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxLayoutFrame)
        static const long ID_MENU_ITEM_QUIT;
        static const long ID_MENU_ITEM_ABOUT;
        static const long ID_STATUSBAR;
        //*)

        //(*Declarations(wxLayoutFrame)
        wxStatusBar* StatusBar;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXLAYOUTMAIN_H
