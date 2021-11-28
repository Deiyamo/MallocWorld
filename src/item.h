//
// Created by TimTim on 01/11/2021.
//

#ifndef MALLOC_WORLD_ITEM_H
#define MALLOC_WORLD_ITEM_H

#include "types.h"

#define MAX_DURABILITY 10;


int checkItemDurability(int casePosition);
Inventory decreaseItemDurability(Inventory inventory, int toolId, int casePosition);

int isItemRepairable(Item item);
Item repairItem(Item item);

char** getItemPropertiesFromFile(Inventory inventory, int casePosition);

void displayCraftableItems(Game* game);
void displayItemName(char* line, const char* separators);

void verifyItemSelected(Game* game, int itemId);

char** getCraftFromFile(char* fileName, const char* separators, int itemId);

char** getCraftAdvancedProperties(char* itemString, const char* separators);
char** getCraftItems(char* itemString, const char* separators);
char** getCraftZones(char* itemString, const char* separators);

void checkIfPlayerHasRequiredItems(int itemId);
void craftItem();
#endif //MALLOC_WORLD_ITEM_H
