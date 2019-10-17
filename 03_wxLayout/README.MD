# 布局控件标记

![布局控件标记](pic\布局控件标记.png)

# Absolute

![绝对布局0](pic\绝对布局0.png)

> 文本框的大小不会随着窗口大小的改变而改变

![绝对布局1](pic\绝对布局1.png)

![绝对布局2](pic\绝对布局2.png)

```cpp
wxLayoutFrame::wxLayoutFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxLayoutFrame)
    
    //xxxxxxxx

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(320,240));

    //文本框放在Panel中
    Panel = new wxPanel(this, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL"));
    TextCtrl = new wxTextCtrl(Panel, ID_TEXTCTRL, _("Text"), wxDefaultPosition, wxSize(200,100), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL"));

    //xxxxxxxx
    //*)
}
```



# Using Sizers

![Sizers0](pic\Sizers0.png)



> wxTextCtrl放置在wxFrame内。 wxFrame具有一个特殊的内置sizer。 我们只能在wxFrame容器中放入一个控件。 该控件占据了wxFrame的所有空间，并随着wxFrame大小的改变而改变。[参考链接](http://zetcode.com/gui/wxwidgets/layoutmanagement/)

![Sizers1](pic\Sizers1.png)

![Sizers2](pic\Sizers2.png)

```cpp
wxLayoutFrame::wxLayoutFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxLayoutFrame)
    
    //xxxxxxxx
    wxTextCtrl* TextCtrl;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(320,240));

    TextCtrl = new wxTextCtrl(this, ID_TEXTCTRL, _("Text"), wxDefaultPosition, wxSize(200,100), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL"));

    //xxxxxxxx
    //*)
}
```



# wxBoxSizer

![wxBoxSizer0](pic\wxBoxSizer0.png)



> 改变窗口大小的时候,wxBoxSizer内的控件会自动按比例重新计算大小,(示例中为 1:2:3)

![wxBoxSizer1](pic\wxBoxSizer1.png)

![wxBoxSizer2](pic\wxBoxSizer2.png)

> wxBoxSizer可以根据需要选择控件排列方向,水平或垂直

![wxBoxSizer3](pic\wxBoxSizer3.png)

![wxBoxSizer4](pic\wxBoxSizer4.png)

```cpp
wxLayoutFrame::wxLayoutFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxLayoutFrame)
    
    // xxxxxxxx
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));

    BoxSizer1 = new wxBoxSizer(wxVERTICAL);

    Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_LEFT, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(Button2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer1->Add(Button3, 3, wxALL|wxALIGN_RIGHT, 5);

    SetSizer(BoxSizer1);
    // xxxxxxxx
    //*)
}
```



## StaticBoxSizer

![StaticBoxSizer0](pic\StaticBoxSizer0.png)

![StaticBoxSizer1](pic\StaticBoxSizer1.png)

```cpp
wxLayoutFrame::wxLayoutFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxLayoutFrame)
    //xxxxxxxx

    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Label"));

    RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    StaticBoxSizer1->Add(RadioButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer1->Add(RadioButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton3 = new wxRadioButton(this, ID_RADIOBUTTON3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    StaticBoxSizer1->Add(RadioButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    SetSizer(StaticBoxSizer1);
    //xxxxxxxx
    //*)
}
```



# wxGridSizer

![wxGridSizer0](pic\wxGridSizer0.png)

> wxGridSizer可以以二维表的方式排列它的子控件,这个二维表中每个表格的大小都是相同的.都等于最长的那个表格的长度和最高的那个表格的高度.

![wxGridSizer1](pic\wxGridSizer1.png)

![wxGridSizer2](pic\wxGridSizer2.png)

```cpp
wxLayoutFrame::wxLayoutFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxLayoutFrame)
    
    //xxxxxxxx
    wxGridSizer* GridSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    GridSizer1 = new wxGridSizer(0, 3, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    GridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("LabelLabelLabel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    GridSizer1->Add(Button2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    GridSizer1->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    GridSizer1->Add(Button3, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button5 = new wxButton(this, ID_BUTTON5, _("LabelLabelLabel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    GridSizer1->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    GridSizer1->Add(Button6, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridSizer1);

    //xxxxxxxx
    //*)
}
```



## FlexGridSizer

![FlexGridSizer0](pic\FlexGridSizer0.png)

![FlexGridSizer1](pic\FlexGridSizer1.png)

![FlexGridSizer2](pic\FlexGridSizer2.png)

```cpp
wxLayoutFrame::wxLayoutFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxLayoutFrame)
    wxFlexGridSizer* FlexGridSizer1;
    
    //xxxxxxxx

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(2);
    FlexGridSizer1->AddGrowableRow(1);
    
    Button1 = new wxButton(this, ID_BUTTON1, _("Label(0,0)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Label(0,1)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer1->Add(Button2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Label(0,2)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer1->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Label(1,0)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer1->Add(Button3, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button5 = new wxButton(this, ID_BUTTON5, _("Label(1,1)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    FlexGridSizer1->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("Label(1,2)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    FlexGridSizer1->Add(Button6, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
    SetSizer(FlexGridSizer1);
    //xxxxxxxx
    //*)
}
```

