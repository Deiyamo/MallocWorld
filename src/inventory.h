//
// Created by TimTim on 24/10/2021.
//

#ifndef MALLOC_WORLD_INVENTORY_H
#define MALLOC_WORLD_INVENTORY_H

#include "types.h"

Inventory starting_inventory();
void displayDebugInventory(Inventory inventory);
void displayLargeInventory(Inventory inventory);
void displayInventoryFromMaxCapacity(Inventory inventory);
void displayInventoryFromCurrentCapacity(Inventory inventory);

Game addItemHarvested(Game* game, char** properties);
Game addItemToInventory(Game* game, char** properties, int quantityHarvested);

Inventory npcStartingInventory();

void repairInventoryStuff(Game* game);

void leaveItemsToStorage(Game* game);
void selectItemToLeave(Game* game);
Game leaveOneItemToStorage(Game* game, int itemNumber);

void takeItemsFromStorage(Game* game);
void selectItemToTake(Game* game);
Game takeOneItemFromStorage(Game* game, int itemNumber);

#endif //MALLOC_WORLD_INVENTORY_H
