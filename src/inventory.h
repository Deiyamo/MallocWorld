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

Inventory npcStartingInventory();

Inventory takeItemsFromStorage(Game* game);
Inventory leaveItemsToStorage(Game* game);

#endif //MALLOC_WORLD_INVENTORY_H
