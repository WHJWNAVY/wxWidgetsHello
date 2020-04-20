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
 
// $Id: Level.h,v 1.2 2005/08/27 14:41:32 technoplaza Exp $

#ifndef _LEVEL_HH_
#define _LEVEL_HH_

#include "EngineConstants.h"

namespace nibbles {
    class Level {
    private:
        unsigned int level;
        
    public:
        /**
         * Creates a new Level.
         */
        Level();
    
        /**
         * Checks if a wall exists at the specified point.
         *
         * @param point The point to check for a wall at.
         *
         * @return true if a wall exists; false otherwise.
         */
        bool isWall(wxPoint point) const;

        /**
         * Gets the current level.
         *
         * @return The level.
         */
        unsigned int getLevel() const;
    };
    
    inline Level::Level() : level(0) {}
    inline unsigned int Level::getLevel() const { return level; }
}

#endif

