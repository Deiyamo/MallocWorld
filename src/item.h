//
// Created by TimTim on 01/11/2021.
//

#ifndef MALLOC_WORLD_ITEM_H
#define MALLOC_WORLD_ITEM_H

#include "types.h"

#define MAX_DURABILITY 10;


int checkItemDurability(int casePosition);
Inventory decreaseItemDurability(Inventory inventory, int toolId, int casePosition);

char** getItemPropertiesFromFile(Inventory inventory, int casePosition);

#endif //MALLOC_WORLD_ITEM_H
