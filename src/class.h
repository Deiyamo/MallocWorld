//
// Created by TimTim on 07/11/2021.
//

#ifndef MALLOC_WORLD_CLASS_H
#define MALLOC_WORLD_CLASS_H

#include "types.h"


int checkPickaxeToUse(Inventory inventory, int casePosition, int currentTool);
int checkPickaxe(Inventory inventory, int pickaxeId, int durabilityNeeded);

#endif //MALLOC_WORLD_CLASS_H
