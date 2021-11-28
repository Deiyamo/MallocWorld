//
// Created by eserban on 22/11/2021.
//

#ifndef MALLOC_WORLD_LOAD_H
#define MALLOC_WORLD_LOAD_H
#define LOAD_DIR_PATH "../saves/"


#include "map.h"
#include "inventory.h"
#include "npc.h"
#include <stdlib.h>

void createZones(Map **map, char* filePath);
Game *load();
void loadMap(Map *map, FILE *mapFile);
Player loadPlayer(FILE *f);
int countAllSaves();
Save* loadAllSaves();
Save getCurrentSave(int choice);
#endif //MALLOC_WORLD_LOAD_H
