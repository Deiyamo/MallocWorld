//
// Created by TimTim on 24/10/2021.
//

#include "level.h"
#include "health.h"
#include <stdio.h>

#define STARTING_XP 100
#define LEVELUP


Level setLevelToZero() {
    Level level;

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

    if(player->level.floor == 2){
        player->health.maxHp = player->health.maxHp + 10;
    } else if(player->level.floor == 3){
        player->health.maxHp = player->health.maxHp + 20;
    } else if(player->level.floor == 4){
        player->health.maxHp = player->health.maxHp + 30;
    } else if(player->level.floor == 5){
        player->health.maxHp = player->health.maxHp + 40;
    } else if((player->level.floor >= 6) && (player->level.floor <= 8)){
        player->health.maxHp = player->health.maxHp + 50;
    } else if((player->level.floor >= 9) && (player->level.floor <= 10)){
        player->health.maxHp = player->health.maxHp + 75;
    }
    set_health_to_max(&player->health);
    player->level.XpMax *= 1.5;
}