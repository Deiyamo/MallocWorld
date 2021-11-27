//
// Created by TimTim on 24/10/2021.
//

#include "level.h"
#include <stdio.h>

#define STARTING_XP 100
#define LEVELUP

Level setLevelToZero() {
    Level level = {};

    level.floor = 1;
    level.maxFloor = 10;
    level.XpCurrent = 0;
    level.XpMax = STARTING_XP;

    return level;
}

/*------------------------------------------------------
    Nicolas update
------------------------------------------------------*/


/* Augmentation de l'xp du joueur et de son niveau si il a l'expérience nécessaire */
void increaseXpPlayer(Player *player, int xp) {
    if( player->level.XpCurrent >= player->level.XpMax ) {
        int newCurrentXp;
        newCurrentXp = player->level.XpMax - player->level.XpCurrent;
        player->level.XpCurrent = newCurrentXp;
        levelUpPlayer(player);
    } else {
        player->level.XpCurrent += xp;
    }
}

/* Augmentation du niveau du joueur */
void levelUpPlayer(Player *player) {
    player->level.floor < player->level.maxFloor ? player->level.floor += 1 : printf("Le joueur a atteind le niveau max \n");
}