//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_DIALOG_H
#define MALLOC_WORLD_DIALOG_H

#include "types.h"

void displayGameTitle();
void displayMenu();
void displayPlayerMenu();
void displayPauseMenu();
void displayControls();
void displayInventoryMenu(Inventory inventory, Game *game);

void displayHelloDialog(char* npcName, Game *game);
void displayNpcMenu();
void displayNpcStorageMenu(Game *game);
void displayLeaveItems(Inventory inventory, Inventory storage);
void displayTakeItems(Inventory inventory, Inventory storage);

void noRequiredEquipment(char* tool);

#endif //MALLOC_WORLD_DIALOG_H
