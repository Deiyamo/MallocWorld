//
// Created by TimTim on 24/10/2021.
//

#include "inventory.h"
#include "dialog.h"
#include "npc.h"
#include "class.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INVENTORY_CAPACITY 10

// Create the player's inventory (4 items and the other slots empty)
Inventory starting_inventory() {

    Inventory inventory = {};
    memset(&inventory, 0, sizeof(Inventory));


    inventory.maxCapacity = INVENTORY_CAPACITY;
    inventory.item = malloc(sizeof(Item) * inventory.maxCapacity);
    for(int i=0 ; i < inventory.maxCapacity ; i++) {
        memset(&inventory.item[i], 0, sizeof(Item)); // put all inventory slots to 0
    }


    // Add some items to the player's inventory
    Item sword = {1, "Wooden sword", 1, 10, {Weapon, 10, 1, 1, 0 , 0}};
    Item pickaxe = {2, "Wooden pickaxe", 1, 10, {Tool, 10, 0, 0, 0 , 0}};
    Item billhook = {3, "Wooden billhook", 1, 10 , {Tool, 10, 0, 0, 0 , 0}};
    Item axe = {4, "Wooden axe", 1, 10, {Tool, 10, 0, 0, 0 , 0}};

    inventory.item[0] = sword; // Wooden sword
    inventory.item[1] = pickaxe; // Wooden pickaxe
    inventory.item[2] = billhook; // Wooden billhook
    inventory.item[3] = axe; // Wooden axe

    // Slots not empty
    inventory.currentCapacity = 4;

    return inventory;
}

// Display debug inventory
void displayDebugInventory(Inventory inventory) {
    for (int i=0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id == 0) {
            printf("VOID");
        } else {
            printf("ID:%d name:%s quantity:%d durability:%d (type:%u-durMax:%d-damage:%d-stack:%d-heal:%d-res:%d)",
                   inventory.item[i].id, inventory.item[i].name, inventory.item[i].quantity, inventory.item[i].durability,
                   inventory.item[i].property.type, inventory.item[i].property.durability_max, inventory.item[i].property.damage, inventory.item[i].property.stack, inventory.item[i].property.heal, inventory.item[i].property.resistance
            );
        }
        printf("\n");
    }
}

// Display inventory in the player's menu
void displayLargeInventory(Inventory inventory) {
    printf("N%c    Item\n", 248);
    for (int i=0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            printf("[%d] - ", i+1);
            checkItemTypeForDisplay(inventory.item[i]);
            printf("\n");
        }
    }
}

// Display inventory from the max capacity  --  Displayed on the main game []
void displayInventoryFromMaxCapacity(Inventory inventory) {
    for (int i=0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id == 0) {
            printf("[ ]");
        } else {
            printf("[%s(%d)]", inventory.item[i].name, inventory.item[i].durability);
        }
        printf(" ");
    }
    printf("\n");
}

// Display inventory from the current capacity
void displayInventoryFromCurrentCapacity(Inventory inventory) {
    for (int i=0; i < inventory.currentCapacity; i++) {
        if (inventory.item[i].id == 0) {
            printf("VOID");
        } else {
            printf("ID:%d name:%s quantity:%d durability:%d (type:%u-durMax:%d-damage:%d-stack:%d-heal:%d-res:%d)",
                   inventory.item[i].id, inventory.item[i].name, inventory.item[i].quantity, inventory.item[i].durability,
                   inventory.item[i].property.type, inventory.item[i].property.durability_max, inventory.item[i].property.damage, inventory.item[i].property.stack, inventory.item[i].property.heal, inventory.item[i].property.resistance
            );
        }
        printf("\n");
    }
    printf("\n");
}


// Insert new Item to storage
Game addItemToInventory(Game* game, char** properties) {
    int quantityHarvested = (rand() % 4) + 1; // random between 0 and 3 then I add 1
    game->player.inventory.currentCapacity += 1;


    // insert new item to inventory
    for (int i = 1; i <= game->player.inventory.maxCapacity; ++i) {
        if (game->player.inventory.item[i].id == 0) {
            game->player.inventory.item[i].id = atoi(properties[0]); // itemToAdd
            game->player.inventory.item[i].name = properties[1];
            //strcpy(game->player.inventory.item[i].name, properties[1]);
            game->player.inventory.item[i].quantity = atoi(properties[2]) * quantityHarvested;
            game->player.inventory.item[i].durability = atoi(properties[3]);
            game->player.inventory.item[i].property.type = stringToEnum(properties[4]);
            game->player.inventory.item[i].property.durability_max = atoi(properties[5]);
            game->player.inventory.item[i].property.damage = atoi(properties[6]);
            game->player.inventory.item[i].property.stack = atoi(properties[7]);
            game->player.inventory.item[i].property.heal = atoi(properties[8]);
            game->player.inventory.item[i].property.resistance = atoi(properties[9]);

            break; // quit loop after the item is inserted
        }
    }

    return *game;
}


/*------------------------------------------------------
    NPC STORAGE
------------------------------------------------------*/

Inventory npcStartingInventory() {

    Inventory storage = {};
    memset(&storage, 0, sizeof(Inventory));

    storage.currentCapacity = 1;
    storage.maxCapacity = 1;

    storage.item = malloc(sizeof(Item) * storage.maxCapacity);
    for(int i=0 ; i < storage.maxCapacity ; i++) {
        memset(&storage.item[i], 0, sizeof(Item)); // set all inventory slots to 0
    }

    // Set first item
    Item excalibur = {99, "Excalibur", 1, 10000, {Weapon, 10000, 10000, 1, 0 , 0}};
    storage.item[0] = excalibur; // Excalibur


    return storage;
}

// https://stackoverflow.com/questions/39985106/dynamically-increase-size-of-array-int-in-c/39985567
/*Inventory addItemIntoStorage(Inventory inventory) {

    if (dynmax >= dunsz) {
        // Oops array too small, expand it by 100 more integers!
        dynsz += 100;
        dynarray = realloc( dynarray, dynsz * sizeof (int) );
    }

}*/

// Process to leave an item to the storage
void leaveItemsToStorage(Game* game) {
    displayLeaveItems(game->player.inventory, game->npc.storage); // display the leave items menu
    selectItemToLeave(game); // leave one item

}

// Select the item from inventory to leave in the storage
void selectItemToLeave(Game* game) {
    char playerStrChoice[5];
    long playerChoice = 0;
    while (playerChoice != -1) {
        fgets(playerStrChoice, 5, stdin);
        playerChoice = strtol(playerStrChoice, NULL, 0);

        if (playerChoice >= 1 && playerChoice <= game->player.inventory.maxCapacity) {

            *game = leaveOneItemToStorage(game, playerChoice-1);

            displayLeaveItems(game->player.inventory, game->npc.storage);
        } else if ( playerChoice == -1 ) {
            displayNpcStorageMenu();
            npcStorageMenuInteractions(game);
        } else {
            displayLeaveItems(game->player.inventory, game->npc.storage);
        }

    }
}

Game leaveOneItemToStorage(Game* game, int itemNumber) {

    if (game->player.inventory.item[itemNumber].id != 0) {
        game->npc.storage.currentCapacity += 1;
        game->npc.storage.maxCapacity += 1;

        // reallocate space in storage
        game->npc.storage.item = realloc(game->npc.storage.item, sizeof(Item) * game->npc.storage.currentCapacity);
        // insert new item to storage
        game->npc.storage.item[game->npc.storage.currentCapacity-1].id = game->player.inventory.item[itemNumber].id;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].name = game->player.inventory.item[itemNumber].name;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].quantity = game->player.inventory.item[itemNumber].quantity;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].durability = game->player.inventory.item[itemNumber].durability;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].property.type = game->player.inventory.item[itemNumber].property.type;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].property.durability_max = game->player.inventory.item[itemNumber].property.durability_max;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].property.damage = game->player.inventory.item[itemNumber].property.damage;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].property.stack = game->player.inventory.item[itemNumber].property.stack;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].property.heal = game->player.inventory.item[itemNumber].property.heal;
        game->npc.storage.item[game->npc.storage.currentCapacity-1].property.resistance = game->player.inventory.item[itemNumber].property.resistance;



        // delete item from inventory and set its slot to 0
        memset(&game->player.inventory.item[itemNumber], 0, sizeof(Item));
        game->player.inventory.currentCapacity -= 1;

        //displayDebugInventory(storage);


    } else {
        printf("This slot is empty...");
    }

    return *game;
}


void takeItemsFromStorage(Game* game){
    displayTakeItems(game->player.inventory, game->npc.storage); // display the take items menu
    selectItemToTake(game); // take one item
}

void selectItemToTake(Game* game) {
    char playerStrChoice[5];
    long playerChoice = 0;
    while (playerChoice != -1) {
        fgets(playerStrChoice, 5, stdin);
        playerChoice = strtol(playerStrChoice, NULL, 0);

        if (playerChoice >= 1 && playerChoice <= game->npc.storage.maxCapacity) {

            *game = takeOneItemFromStorage(game, playerChoice-1);

            displayTakeItems(game->player.inventory, game->npc.storage);
        } else if ( playerChoice == -1 ) {
            displayNpcStorageMenu();
            npcStorageMenuInteractions(game);
        } else {
            displayTakeItems(game->player.inventory, game->npc.storage);
        }

    }
}

// The player will take an item from the storage to their inventory
Game takeOneItemFromStorage(Game* game, int itemNumber) {

    if (game->npc.storage.item[itemNumber].id != 0) {
        if (game->player.inventory.currentCapacity <= game->player.inventory.maxCapacity) {

            game->player.inventory.currentCapacity += 1;

            // insert new item to inventory
            for (int i = 1; i <= game->player.inventory.maxCapacity; ++i) {
                if (game->player.inventory.item[i].id == 0) {
                    game->player.inventory.item[i].id = game->npc.storage.item[itemNumber].id;
                    game->player.inventory.item[i].name = game->npc.storage.item[itemNumber].name;
                    game->player.inventory.item[i].quantity = game->npc.storage.item[itemNumber].quantity;
                    game->player.inventory.item[i].durability = game->npc.storage.item[itemNumber].durability;
                    game->player.inventory.item[i].property.type = game->npc.storage.item[itemNumber].property.type;
                    game->player.inventory.item[i].property.durability_max = game->npc.storage.item[itemNumber].property.durability_max;
                    game->player.inventory.item[i].property.damage = game->npc.storage.item[itemNumber].property.damage;
                    game->player.inventory.item[i].property.stack = game->npc.storage.item[itemNumber].property.stack;
                    game->player.inventory.item[i].property.heal = game->npc.storage.item[itemNumber].property.heal;
                    game->player.inventory.item[i].property.resistance = game->npc.storage.item[itemNumber].property.resistance;

                    break; // quit loop after the item is inserted
                }
            }

            // delete item from storage and set its slot to 0
            memset(&game->npc.storage.item[itemNumber], 0, sizeof(Item));
            game->npc.storage.currentCapacity -= 1;
        } else {
            printf("Your inventory is full, you cant take more items.");
        }
    } else {
        printf("This slot is empty...");
    }

    return *game;
}