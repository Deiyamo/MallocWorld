//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_PLAYER_H
#define MALLOC_WORLD_PLAYER_H

#include "types.h"

Player newPlayer();
int chooseWeaponFight();
void attack();
void damage();
void escapeFight();
void actionPlayer();
void openPortail();
void killPlayer();

void displayPlayer();
void displayPlayerFight();
void displayPlayerPosition();
void displayInteractionPlayer();


#endif //MALLOC_WORLD_PLAYER_H
