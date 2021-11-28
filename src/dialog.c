//
// Created by TimTim on 23/10/2021.
//

#include "dialog.h"
#include <stdio.h>
#include "events.h"
#include "inventory.h"
#include "load.h"


// Display the name of the game
void displayGameTitle() {
    printf("\n   _____         .__  .__                   __      __            .__       .___\n"
           "  /     \\ _____  |  | |  |   ____   ____   /  \\    /  \\___________|  |    __| _/\n"
           " /  \\ /  \\\\__  \\ |  | |  |  /  _ \\_/ ___\\  \\   \\/\\/   /  _ \\_  __ \\  |   / __ |\n"
           "/    Y    \\/ __ \\|  |_|  |_(  <_> )  \\___   \\        (  <_> )  | \\/  |__/ /_/ |\n"
           "\\____|__  (____  /____/____/\\____/ \\___  >   \\__/\\  / \\____/|__|  |____/\\____ |\n"
           "        \\/     \\/                      \\/         \\/                         \\/\n");

    printf("\n\n");
}

// Display the starting menu
void displayMenu() {
    clear_screen();
    displayGameTitle();

    printf("1) New game \n");
    printf("2) Load game\n");
    printf("3) Controls\n");
    printf("4) Items\n");
    printf("5) Exit\n");
    printf(":");
}

// Display the actions that the player can do
void displayPlayerMenu() {
    printf("z - move up\n");
    printf("q - move left\n");
    printf("s - move down\n");
    printf("d - move right\n");
    printf("i - open inventory\n");
    printf("p - pause\n");
    printf(":");
}

// Display the actions in the pause menu
void displayPauseMenu() {
    clear_screen();

    printf("\n\tPAUSE MENU\n\n");
    printf("  1) Resume\n"
           "  2) Save\n"
           "  3) Back to menu\n"
           "\n :");
}


// Display the controls
void displayControls() {
    clear_screen();

    printf("\n\t\tControls\n\n");
    printf("  z - move up\n"
           "  q - move left\n"
           "  s - move down\n"
           "  d - move right\n"
           "  (you can use the arrow keys too)\n\n"
           "  p - pause the game\n\n\n\n"
           "  press enter to go back to the menu...\n");

    int enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    clear_screen();
}


void displayInventoryMenu(Inventory inventory, Game* game) {
    clear_screen();

    printf("\n\t\tINVENTORY (%d/%d)\n\n", inventory.currentCapacity, inventory.maxCapacity);

    displayLargeInventory(inventory);

    printf("\npress enter to go back to the game...\n");
    int enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    restore_screen(game);
}



/*------------------------------------------------------
    NPC DIALOG
------------------------------------------------------*/

void displayHelloDialog(char* npcName, Game *game) {
    restore_screen(game);

    printf("%s :\n", npcName);
    printf("Hello, I'm %s. Be careful around here, there is a lot of monsters. ", npcName);
    printf("Do you need something from me ?\n");

    displayNpcMenu();
}

void displayNpcMenu() {
    printf("1) Repair stuff\n");
    printf("2) Craft item\n");
    printf("3) Storage\n");
    printf("4) Bye...\n");
    printf(":");
}

void displayNpcStorageMenu(Game *game) {
    restore_screen(game);

    printf("1) Leave items\n");
    printf("2) Take items\n");
    printf("3) Bye...\n");
    printf(":");
}

void displayLeaveItems(Inventory inventory, Inventory storage) {
    clear_screen();

    printf("\n\t\tSTORAGE (%d)\n\n", storage.currentCapacity);
    displayLargeInventory(storage);

    printf("\n");

    printf("\n\t\tINVENTORY (%d/%d)\n\n", inventory.currentCapacity, inventory.maxCapacity);
    displayLargeInventory(inventory);

    printf("\nSelect an item you want to leave in the storage. Or press '-1' to go back to the storage menu.\n");
}

void displayTakeItems(Inventory inventory, Inventory storage) {
    clear_screen();

    printf("\n\t\tINVENTORY (%d/%d)\n\n", inventory.currentCapacity, inventory.maxCapacity);
    displayLargeInventory(inventory);

    printf("\n");

    printf("\n\t\tSTORAGE (%d)\n\n", storage.currentCapacity);
    displayLargeInventory(storage);

    printf("\nSelect an item you want to take from the storage. Or press '-1' to go back to the storage menu.\n");
}


/*------------------------------------------------------
    COLLECT RESSOURCES DIALOG
------------------------------------------------------*/

void noRequiredEquipment(char* tool) {
    printf("\nYou don't have the required %s or your %s needs to be repair.\n", tool, tool);
}