# _T("xxx") 和 wxT("xxx")

> _T("xxx") 和 wxT("xxx") 功能相同, 为了兼容unicode

```cpp
wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    //xxxxxx
        wxbuild << _T("-Windows"); // _T("xxx") 和 wxT("xxx") 功能相同, 为了兼容unicode
    //xxxxxx

    return wxbuild;
}
```

# _("xxx")

> _("xxx") 为了把字符串翻译成指定的语言

```cpp
void wxHelloFrame::OnButtonHelloClick(wxCommandEvent &event)
{
    wxString msgs = _("Hello World!");
    wxMessageBox(msgs, _("wxHelloWorld")); // _("xxx") 为了把字符串翻译成指定的语言
}
```



# IMPLEMENT_APP 和 DECLARE_APP

> IMPLEMENT_APP(xxx) 是告诉wxWidgets要创建哪个类的实例
>
> DECLARE_APP(xxx) 是为了让wxGetApp()返回xxx类的实例

```cpp
IMPLEMENT_APP(wxHelloApp); //告诉wxWidgets要创建哪个类的实例
//DECLARE_APP(wxHelloApp);   //为了让wxGetApp()返回wxHelloApp类的实例
```



# 动态事件表

> DECLARE_EVENT_TABLE() 是为了声明动态事件表

```cpp
BEGIN_EVENT_TABLE(wxHelloFrame, wxFrame)
//(*EventTable(wxHelloFrame) 静态事件表
    EVT_MENU(ID_MENUITEM_QUIT, wxHelloFrame::OnQuit)
    EVT_MENU(ID_MENU_ABOUT, wxHelloFrame::OnAbout)
    EVT_BUTTON(ID_BUTTON_HELLO, wxHelloFrame::OnButtonHelloClick)
//*)
END_EVENT_TABLE()
```



# 静态事件表

```cpp
wxHelloFrame::wxHelloFrame(wxWindow *parent, wxWindowID id)
{
    // xxxxxx
    Connect(ID_BUTTON_HELLO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxHelloFrame::OnButtonHelloClick);
    Connect(ID_MENUITEM_QUIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxHelloFrame::OnQuit);
    Connect(ID_MENU_ABOUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxHelloFrame::OnAbout);
    // xxxxxx
}

void wxHelloFrame::OnQuit(wxCommandEvent &event)
{
    Close();
}

void wxHelloFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxHelloFrame::OnButtonHelloClick(wxCommandEvent &event)
{
    wxString msgs = _("Hello World!");
    wxMessageBox(msgs, _("wxHelloWorld")); // _("xxx") 为了把字符串翻译成指定的语言
}
```

