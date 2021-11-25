//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_MAP_H
#define MALLOC_WORLD_MAP_H

#define ROWS 15
#define COLUMNS 15

#include "types.h"

void createMap();
void defaultMap();
void displayMap();


// will go to the point.h later
Game checkFuturePosition(Game* game, int x, int y);
int isPositionWalkable(int x, int y);

Point getPlayerPosition();
void updatePlayerPositionOnMap(Point position, int newX, int newY);
Point updatePlayerPosition(Point position, int newX, int newY);

#endif //MALLOC_WORLD_MAP_H
