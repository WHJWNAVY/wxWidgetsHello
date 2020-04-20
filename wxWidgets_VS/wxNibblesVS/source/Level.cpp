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
 
// $Id: Level.cc,v 1.2 2005/08/27 14:41:32 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include "Level.h"
#include "LevelData.h"

using namespace nibbles;

bool Level::isWall(wxPoint point) const {
    point.x /= BLOCK_SIZE;
    point.y /= BLOCK_SIZE;
    
    return (LEVEL_DATA[level][point.y][point.x] == 1);
}

