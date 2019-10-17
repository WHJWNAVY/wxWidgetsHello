/***************************************************************
 * Name:      wxLayoutApp.cpp
 * Purpose:   Code for Application Class
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-17
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#include "wxLayoutApp.h"

//(*AppHeaders
#include "wxLayoutMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxLayoutApp);

bool wxLayoutApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxLayoutFrame* Frame = new wxLayoutFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
