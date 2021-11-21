//
// Created by TimTim on 07/11/2021.
//

#ifndef MALLOC_WORLD_CLASS_H
#define MALLOC_WORLD_CLASS_H

#include "types.h"


void checkItemTypeForDisplay(Item item);
void displayWeapon(Item item);
void displayTool(Item item);
void displayCraft(Item item);
void displayArmor(Item item);
void displayHeal(Item item);

Class stringToEnum(const char* itemType);
int checkPickaxeToUse(Inventory inventory, int casePosition, int currentTool);
int checkPickaxe(Inventory inventory, int pickaxeId, int durabilityNeeded);

#endif //MALLOC_WORLD_CLASS_H
