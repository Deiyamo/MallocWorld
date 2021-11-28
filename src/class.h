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

void checkItemTypeForDisplaySimplified(Item item);
void displayWeaponSimplified(Item item);
void displayToolSimplified(Item item);
void displayCraftSimplified(Item item);
void displayArmorSimplified(Item item);
void displayHealSimplified(Item item);


Class stringToEnum(const char* itemType);
int checkClass(Inventory inventory, Class type);

int checkBillhookToUse(Inventory inventory, int casePosition, int currentTool);
int checkBillhook(Inventory inventory, int billhookId, int durabilityNeeded);
int checkPickaxeToUse(Inventory inventory, int casePosition, int currentTool);
int checkPickaxe(Inventory inventory, int pickaxeId, int durabilityNeeded);
int checkAxeToUse(Inventory inventory, int casePosition, int currentTool);
int checkAxe(Inventory inventory, int axeId, int durabilityNeeded);

#endif //MALLOC_WORLD_CLASS_H
