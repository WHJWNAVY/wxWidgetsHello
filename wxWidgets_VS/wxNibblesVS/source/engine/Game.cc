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
 
// $Id: Game.cc,v 1.9 2005/08/27 15:29:10 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <cstdlib>

#include "engine/Game.hh"
#include "engine/Snake.hh"
#include "engine/Timer.hh"
#include "ui/NibblesPanel.hh"

using namespace nibbles;

const int Game::LIVES[] = { 8, 5, 3 };
const int Game::SPEEDS[] = { 250, 125, 63 };

Game::Game(NibblesPanel &panel) : snake(NULL), panel(panel), 
                                  difficulty(AVERAGE),
                                  playing(false), paused(true) {
    // create the game Timer
    timer = new Timer(*this);
}

Game::~Game() {
    // end the Game
    end();
    
    // delete the Timer
    delete timer;
}

void Game::start(enum Difficulty difficulty) {
    // end the current Game
    end();
    
    // setup the game parameters
    this->difficulty = difficulty;
    
    // create the snake
    int temp = static_cast<int>(difficulty);
    snake = new Snake(LIVES[temp]);
    
    // randomize apple position
    moveApple();
    
    // now we are playing
    playing = true;
}

void Game::restart() {
    // pause the Game
    paused = true;
    timer->Stop();
    
    // reincarnate the snake
    snake->reincarnate();
    
    // randomize apple position
    moveApple();
    
    // refresh the display
    panel.Refresh();
}

void Game::end() {
    // if we are playing
    if (playing) {
        // stop playing
        playing = false;
        
        // stop the Timer
        timer->Stop();
        
        // remove the snake
        delete snake;
    }
}

void Game::changeDirection(enum Direction direction) {
    snake->setDirection(direction);
}

void Game::togglePause() {
    // toggle pause value
    paused = !paused;
    
    if (paused) {
        // stop the timer
        timer->Stop();
    } else {
        // (re)start the timer
        timer->Start(SPEEDS[difficulty]);
    }
}

bool Game::isOccupied(const wxPoint &point, bool checkHead) const {
    int start = (checkHead ? 0 : 1);
    
    // is the point occupied by the Snake
    for (unsigned int i = start; i < snake->getSegments().size(); i++) {
        if (point == snake->getSegments()[i]) {
            return true;
        }
    }
    
    // is the point occupied by a Wall?
    if (level.isWall(point)) {
        return true;
    }
    
    return false;
}

void Game::moveApple() {
    for (;;) {
        // find a random spot for the apple
        apple.x = (rand() / ((RAND_MAX / (PANEL_WIDTH / BLOCK_SIZE)) + 1)) * BLOCK_SIZE;
        apple.y = (rand() / ((RAND_MAX / (PANEL_HEIGHT / BLOCK_SIZE)) + 1)) * BLOCK_SIZE;
    
        if (!isOccupied(apple, true)) {
            // if we found a free spot, we're done
            break;
        }
        
        // otherwise we have to keep looking
    }
}

void Game::tick() {
    // move the snake
    snake->move();
    
    // did the snake crash?
    if (isOccupied(snake->getSegments()[0])) {
        snake->setAlive(false);
        snake->subtractLife();
    }
    
    // did the snake eat the apple?
    if (snake->getSegments()[0] == apple) {
        // randomize the apple position
        moveApple();
        
        // grow the snake
        snake->addSegment(3);
    }
    
    // refresh the panel
    panel.Refresh();
}

