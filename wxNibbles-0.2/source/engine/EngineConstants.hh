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
 
// $Id: EngineConstants.hh,v 1.6 2005/08/27 14:41:32 technoplaza Exp $

#ifndef _ENGINECONSTANTS_HH_
#define _ENGINECONSTANTS_HH_

#include "ui/UIConstants.hh"

namespace nibbles {
    /// The direction the Snake is moving in
    enum Direction {
        NORTH, EAST, SOUTH, WEST
    };
    
    /// The difficulty setting of the Game
    enum Difficulty {
        NOVICE, AVERAGE, EXPERT
    };
    
    /// The number of levels defined
    const unsigned int LEVELS = 1;
    
    /// The level data
    extern const unsigned char LEVEL_DATA[LEVELS]
                                         [PANEL_HEIGHT / BLOCK_SIZE]
                                         [PANEL_WIDTH / BLOCK_SIZE];
}

#endif

