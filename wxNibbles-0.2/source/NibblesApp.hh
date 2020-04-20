/*
 * wxNibbles
 * Copyright (C) 2005 CODEpendent
 * http://code.technoplaza.net/wxNibbles/
 *
 * This file is part of wxNibbles.
 *
 * wxNibbles is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wxNibbles is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with wxNibbles; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
// $Id: NibblesApp.hh,v 1.5 2005/08/27 14:41:32 technoplaza Exp $

#ifndef _NIBBLESAPP_HH_
#define _NIBBLESAPP_HH_

namespace nibbles {
    class NibblesApp : public wxApp {
        DECLARE_CLASS(NibblesApp)
        
    public:
        /**
         * Creates a new NibblesApp.
         */
        NibblesApp();
        
        /**
         * Destructs this NibblesApp.
         */
        ~NibblesApp();
        
        /**
         * Called to initialize this NibblesApp.
         *
         * @return true if initialization succeeds; false otherwise.
         */
        bool OnInit();
    };
    
    DECLARE_APP(NibblesApp)
}

#endif

