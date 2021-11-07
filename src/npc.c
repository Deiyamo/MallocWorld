//
// Created by TimTim on 31/10/2021.
//

#include "npc.h"

#include <stdio.h>

#include "inventory.h"
#include "dialog.h"
#include "events.h"


// Create the game's npc (will be present in all zones)
Npc newNpc() {
    Npc npc = {};
    npc.name = "Bob";
    npc.storage = npcStartingInventory();

    return npc;
}


Game interactWithNpc(Game* game) {
    // Restore screen and display the hello dialog
    displayHelloDialog(game->npc.name); // with displayNpcMenu() in it
    // Display the npc menu interactions
    npcMenuInteractions(game);

    return *game;
}

void npcMenuInteractions(Game* game) {

    int npcMenuChoice = getchar();
    getchar();

    switch (npcMenuChoice) {
        case '1': // Repair stuff
            printf("Repair stuff");
            break;
        case '2': // Craft item
            printf("Craft item");
            break;
        case '3': // Storage
            displayNpcStorageMenu();
            npcStorageMenuInteractions(game);
            break;
        case '4': // Bye...
            break;
        default:
            restore_screen();
            displayNpcMenu();
            npcMenuInteractions(game);
    }
}

void npcStorageMenuInteractions(Game* game) {
    int npcStorageMenuChoice = getchar();
    getchar();

    switch (npcStorageMenuChoice) {
        case '1': // Leave items
            printf("Leave items");
            leaveItemsToStorage(game);
            break;
        case '2': // Take items
            printf("Take items");
            takeItemsFromStorage(game);
            break;
        case '3': // Bye...
            break;
        default:
            displayNpcStorageMenu();
            npcStorageMenuInteractions(game);
    }
}