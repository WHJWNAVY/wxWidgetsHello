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
 
// $Id: Timer.h,v 1.3 2005/08/27 14:41:32 technoplaza Exp $

#ifndef _TIMER_HH_
#define _TIMER_HH_

#include <wx/timer.h>

#include "Game.h"

namespace nibbles {
    class Timer : public wxTimer {
    private:
        Game &game;
    
        /**
         * Called when the timer goes off.
         */
        void Notify();
        
    public:
        /**
         * Creates a new Timer.
         *
         * @param game The Game to notify when this Timer goes off.
         */
        Timer(Game &game);
    };
    
    inline Timer::Timer(Game &game) : wxTimer(), game(game) {}
    inline void Timer::Notify() { game.tick(); }
}

#endif

