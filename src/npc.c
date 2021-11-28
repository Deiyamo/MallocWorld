//
// Created by TimTim on 31/10/2021.
//

#include "npc.h"

#include <stdio.h>
#include <stdlib.h>

#include "inventory.h"
#include "item.h"
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
            repairInventoryStuff(game);
            printf("*** Your stuff has been repaired ! ***\n");
            getchar();
            break;
        case '2': // Craft item
            printf("Craft item\n");
            npcCraftItemMenu(game);
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

void npcCraftItemMenu(Game* game) {
    clear_screen();
    displayCraftableItems(game); // Display all craftable items

    printf("\nEnter the item's ID you want to craft. Or press \"-1\" to return to the menu.\n:");

    char playerStrChoice[5];
    long playerChoice = 0;
    while (playerChoice != -1) {
        fgets(playerStrChoice, 5, stdin);
        playerChoice = strtol(playerStrChoice, NULL, 0);

        if (playerChoice >= 1 && playerChoice <= 25) {

            verifyItemSelected(game, playerChoice-1);
            break;

        } else if ( playerChoice == -1 ) {
            clear_screen();
            displayNpcMenu();
            npcMenuInteractions(game);
        } else {
            npcCraftItemMenu(game);
        }
    }
    printf("done verifying");

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