/***************************************************************
 * Name:      wxWindowApp.cpp
 * Purpose:   Code for Application Class
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-16
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#include "wxWindowApp.h"

//(*AppHeaders
#include "wxWindowMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxWindowApp);

bool wxWindowApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxWindowFrame* Frame = new wxWindowFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
