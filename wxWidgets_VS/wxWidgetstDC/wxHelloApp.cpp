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

IMPLEMENT_APP(wxHelloApp); //����wxWidgetsҪ�����ĸ����ʵ��
//DECLARE_APP(wxHelloApp);   //Ϊ����wxGetApp()����wxHelloApp���ʵ��

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
