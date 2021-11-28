//
// Created by Nico on 01/11/2021.
//

#ifndef MALLOC_WORLD_MONSTER_H
#define MALLOC_WORLD_MONSTER_H

#include "types.h"

Monster createMonster();

void displayMonster();
void displayActionMonster(Game* game, Fight *fight);

void attackMonster();
void dropXpMonster();
void killMonster();


#endif //MALLOC_WORLD_MONSTER_H
