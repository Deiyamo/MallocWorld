//
// Created by TimTim on 17/10/2021.
//

#ifndef MALLOC_WORLD_SAVE_H

#include "types.h"
#define MALLOC_WORLD_SAVE_H

void saveMap(Map *map, FILE *f);
void saveGame(Game *game);
void saveInventory(Inventory inventory, FILE *f);
void savePlayer(Player player, FILE *f);
void saveNpc(Npc npc, FILE *f);

#endif //MALLOC_WORLD_SAVE_H
