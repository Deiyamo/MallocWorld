//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_PLAYER_H
#define MALLOC_WORLD_PLAYER_H

#include "types.h"

Player newPlayer();
void movePlayer();
void XPincrease_player();
void levelUp_player();


void display_player(Player player);
void displayPlayerPosition(Point position);

void harvestRock();
void harvestPlant();
void harvestTree();


void kill_player();


#endif //MALLOC_WORLD_PLAYER_H
