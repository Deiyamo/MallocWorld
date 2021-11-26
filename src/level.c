//
// Created by TimTim on 24/10/2021.
//

#include "level.h"

#define STARTING_XP 100

Level set_level_to_zero() {

    Level level;

    level.floor = 1;
    level.XPcurrent = 0;
    level.XPmax = STARTING_XP;

    return level;
}