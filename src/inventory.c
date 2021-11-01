//
// Created by TimTim on 24/10/2021.
//

#include "inventory.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INVENTORY_CAPACITY 10

// Create the player's inventory (4 items and the other slots empty)
Inventory starting_inventory() {

    Inventory inventory = {};
    memset(&inventory, 0, sizeof(Inventory));


    inventory.maxCapacity = INVENTORY_CAPACITY;
    inventory.objects = malloc(sizeof(Item) * inventory.maxCapacity);
    for(int i=0 ; i < inventory.maxCapacity ; i++) {
        memset(&inventory.objects[i], 0, sizeof(Item)); // put all inventory slots to 0
    }


    // Add some items to the player's inventory
    Item sword = {1, "Wooden sword", 1, 10, {Weapon, 10, 1, 1, 0 , 0}};
    Item pickaxe = {2, "Wooden pickaxe", 1, 10, {Tool, 10, 0, 1, 0 , 0}};
    Item billhook = {3, "Wooden billhook", 1, 10 , {Tool, 10, 0, 1, 0 , 0}};
    Item axe = {4, "Wooden axe", 1, 10, {Tool, 10, 0, 1, 0 , 0}};

    inventory.objects[0] = sword; // Wooden sword
    inventory.objects[1] = pickaxe; // Wooden pickaxe
    inventory.objects[2] = billhook; // Wooden billhook
    inventory.objects[3] = axe; // Wooden axe

    // Slots not empty
    inventory.currentCapacity = 4;

    return inventory;
}

// Display debug inventory
void displayDebugInventory(Inventory inventory) {
    for (int i=0; i < inventory.maxCapacity; i++) {
        if (inventory.objects[i].id == 0) {
            printf("VOID");
        } else {
            printf("ID:%d name:%s quantity:%d durability:%d (type:%u-durMax:%d-damage:%d-stack:%d-heal:%d-res:%d)",
                   inventory.objects[i].id, inventory.objects[i].name, inventory.objects[i].quantity, inventory.objects[i].durability,
                   inventory.objects[i].property.type, inventory.objects[i].property.durability_max, inventory.objects[i].property.damage, inventory.objects[i].property.stack, inventory.objects[i].property.heal, inventory.objects[i].property.resistance
            );
        }
        printf("\n");
    }
}

// Display debug inventory
void displayLargeInventory(Inventory inventory) {
    for (int i=0; i < inventory.currentCapacity; i++) {
        if (inventory.objects[i].id == 0) {
            printf("VOID");
        } else {
            checkItemTypeForDisplay(inventory.objects[i]);
        }
        printf("\n");
    }
}

// Display inventory from the max capacity
void displayInventoryFromMaxCapacity(Inventory inventory) {
    for (int i=0; i < inventory.maxCapacity; i++) {
        if (inventory.objects[i].id == 0) {
            printf("[ ]");
        } else {
            printf("[%s(%d)]", inventory.objects[i].name, inventory.objects[i].durability);
        }
        printf(" ");
    }
    printf("\n");
}

// Display inventory from the current capacity
void displayInventoryFromCurrentCapacity(Inventory inventory) {
    for (int i=0; i < inventory.currentCapacity; i++) {
        if (inventory.objects[i].id == 0) {
            printf("VOID");
        } else {
            printf("ID:%d name:%s quantity:%d durability:%d (type:%u-durMax:%d-damage:%d-stack:%d-heal:%d-res:%d)",
                   inventory.objects[i].id, inventory.objects[i].name, inventory.objects[i].quantity, inventory.objects[i].durability,
                   inventory.objects[i].property.type, inventory.objects[i].property.durability_max, inventory.objects[i].property.damage, inventory.objects[i].property.stack, inventory.objects[i].property.heal, inventory.objects[i].property.resistance
            );
        }
        printf("\n");
    }
    printf("\n");
}




Inventory npcStartingInventory() {

    Inventory storage = {};
    memset(&storage, 0, sizeof(Inventory));

    storage.currentCapacity = 1;
    storage.maxCapacity = 1;

    storage.objects = malloc(sizeof(Item) * storage.maxCapacity);
    for(int i=0 ; i < storage.maxCapacity ; i++) {
        memset(&storage.objects[i], 0, sizeof(Item)); // set all inventory slots to 0
    }

    // Set first item
    Item excalibur = {99, "Excalibur", 1, 10000, {Weapon, 10000, 10000, 1, 0 , 0}};
    storage.objects[0] = excalibur; // Excalibur


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

Inventory takeItemsFromStorage(Game* game){

}

Inventory leaveItemsToStorage(Game* game) {

}