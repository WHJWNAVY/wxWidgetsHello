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
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/sizer.h>
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
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxLayoutFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON4;
        static const long ID_BUTTON3;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_MENUITEM1;
        static const long ID_MENU_ITEM_ABOUT;
        static const long ID_STATUSBAR;
        //*)

        //(*Declarations(wxLayoutFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxButton* Button5;
        wxButton* Button6;
        wxStatusBar* StatusBar;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXLAYOUTMAIN_H
