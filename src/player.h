//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_PLAYER_H
#define MALLOC_WORLD_PLAYER_H

#include "types.h"

Player newPlayer();
int chooseWeaponFight();
void attack();
void damagePlayer();
void escapeFight();
void actionPlayer(); 
void killPlayer();

void healthPlayer();
void displayChoosePotion();
int choosePotionFight();

void displayChooseWeapon();
void displayPlayer();
void displayPlayerFight();
void displayPlayerPosition();
void displayInteractionPlayer();


#endif //MALLOC_WORLD_PLAYER_H
