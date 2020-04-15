/***************************************************************
 * Name:      wxLayoutApp.cpp
 * Purpose:   Code for Application Class
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-17
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#include "wxFormBuilderHelloApp.h"

 //(*AppHeaders
#include "wxFormBuilderHelloMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxLayoutApp);

bool wxLayoutApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if (wxsOK)
    {
        MyFrameHello* Frame = new MyFrameHello(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
