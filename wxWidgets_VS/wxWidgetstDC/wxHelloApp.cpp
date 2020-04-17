/***************************************************************
 * Name:      wxHelloApp.cpp
 * Purpose:   Code for Application Class
 * Author:    whjwnavy (whjwnavy@163.com)
 * Created:   2019-10-16
 * Copyright: whjwnavy (www.wnavy.com)
 * License:
 **************************************************************/

#include "wxHelloApp.h"

 //(*AppHeaders
#include "wxWidgetstDCMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxHelloApp); //告诉wxWidgets要创建哪个类的实例
//DECLARE_APP(wxHelloApp);   //为了让wxGetApp()返回wxHelloApp类的实例

bool wxHelloApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if (wxsOK)
    {
        MyFrameHello *Frame = new MyFrameHello(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
}
