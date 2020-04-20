/////////////////////////////////////////////////////////////////////////////
// Name:        HabraSnakeApp.h
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     30/11/2008 03:51:52
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008-2009
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _HABRASNAKEAPP_H_
#define _HABRASNAKEAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "HabraSnakeMainFrame.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations
class wxDocManager;

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * HabraSnakeApp class declaration
 */

class HabraSnakeApp: public wxApp
{    
    DECLARE_CLASS( HabraSnakeApp )
    DECLARE_EVENT_TABLE()
	
	wxDocManager * m_DocManager;
public:
    /// Constructor
    HabraSnakeApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin HabraSnakeApp event handler declarations

////@end HabraSnakeApp event handler declarations

////@begin HabraSnakeApp member function declarations

////@end HabraSnakeApp member function declarations

////@begin HabraSnakeApp member variables
////@end HabraSnakeApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(HabraSnakeApp)
////@end declare app

#endif
    // _HABRASNAKEAPP_H_
