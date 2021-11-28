//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_MAP_H
#define MALLOC_WORLD_MAP_H

#include <stdio.h>
#include <string.h>
#include "types.h"

//void createMap();
void defaultMap();
void initMap(Map *map, int type);
void displayMap(Game *game);


// will go to the point.h later
int checkFuturePosition(Game *game, int x, int y);
int isPositionWalkable(Map *map, int x, int y);
Point getPlayerPosition(Map *map);
void updatePlayerPositionOnMap(Point position, int newX, int newY, Map *map);
Point updatePlayerPosition(Point position, int newX, int newY);

#endif //MALLOC_WORLD_MAP_H
