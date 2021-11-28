//
// Created by eserban on 22/11/2021.
//

#ifndef MALLOC_WORLD_GENERATE_H
#define MALLOC_WORLD_GENERATE_H


#define NB_MONSTERS_MIN 10
#define NB_ROCKS_MIN 5
#define NB_PLANTS_MIN 6
#define NB_TREES_MIN 3
#define NB_WALLS (ROWS*COLUMNS)*0.1

#include "map.h"

void generateMonsters(Map *map);
void generateRocks(Map *map);
void generatePlants(Map *map);
void generateTrees(Map *map);
void placePlayer(Map *map);
void placePNJ(Map *map);
void placePortal(Map *map);
void placeWalls(Map *map);
Map **generate();

#endif //MALLOC_WORLD_GENERATE_H
