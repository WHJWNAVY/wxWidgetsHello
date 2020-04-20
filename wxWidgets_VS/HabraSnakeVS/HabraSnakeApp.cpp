/////////////////////////////////////////////////////////////////////////////
// Name:        HabraSnakeApp.cpp
// Purpose:     
// Author:      Volodymir (T-Rex) Tryapichko
// Modified by: 
// Created:     30/11/2008 03:51:52
// RCS-ID:      
// Copyright:   Volodymir (T-Rex) Tryapichko, 2008-2009
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "HabraSnakeApp.h"
#include "HabraSnakeDocument.h"
#include "HabraSnakeView.h"

////@begin XPM images
////@end XPM images


/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( HabraSnakeApp )
////@end implement app


/*!
 * HabraSnakeApp type definition
 */

IMPLEMENT_CLASS( HabraSnakeApp, wxApp )


/*!
 * HabraSnakeApp event table definition
 */

BEGIN_EVENT_TABLE( HabraSnakeApp, wxApp )

////@begin HabraSnakeApp event table entries
////@end HabraSnakeApp event table entries

END_EVENT_TABLE()


/*!
 * Constructor for HabraSnakeApp
 */

HabraSnakeApp::HabraSnakeApp()
{
    Init();
}


/*!
 * Member initialisation
 */

void HabraSnakeApp::Init()
{
////@begin HabraSnakeApp member initialisation
////@end HabraSnakeApp member initialisation
	m_DocManager = new wxDocManager;
	m_DocManager->SetMaxDocsOpen(1);
	new wxDocTemplate(m_DocManager, _("HabraSnake Game"), wxEmptyString, wxEmptyString,
		wxEmptyString, wxT("HabraSnakeDoc"), wxT("HabraSnakeView"), 
		CLASSINFO(HabraSnakeDocument), CLASSINFO(HabraSnakeView));
}

/*!
 * Initialisation for HabraSnakeApp
 */

bool HabraSnakeApp::OnInit()
{
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
	HabraSnakeMainFrame* mainWindow = new HabraSnakeMainFrame( m_DocManager,  NULL);
	SetTopWindow(mainWindow);
	mainWindow->Show(true);
    return true;
}


/*!
 * Cleanup for HabraSnakeApp
 */

int HabraSnakeApp::OnExit()
{
	wxDELETE(m_DocManager);
////@begin HabraSnakeApp cleanup
	return wxApp::OnExit();
////@end HabraSnakeApp cleanup
}

