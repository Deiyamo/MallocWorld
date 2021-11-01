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
void displayInventoryMenu(Inventory inventory);

void displayHelloDialog(char* npcName);
void displayNpcMenu();
void displayNpcStorageMenu();

#endif //MALLOC_WORLD_DIALOG_H
