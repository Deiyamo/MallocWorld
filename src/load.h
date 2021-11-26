//
// Created by eserban on 22/11/2021.
//

#ifndef MALLOC_WORLD_LOAD_H
#define MALLOC_WORLD_LOAD_H
#define MAP_LOAD_FILE_PATH "D:\\Perso\\MallocWorld\\saves\\save.log"


#include "map.h"
#include <stdlib.h>

void createZones(Map **map);
Map** load();
void loadMap(Map *map, FILE *mapFile);
#endif //MALLOC_WORLD_LOAD_H
