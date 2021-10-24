//
// Created by TimTim on 24/10/2021.
//

#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INVENTORY_CAPACITY 10

// Create the player's inventory (4 items and the other slots empty)
Inventory starting_inventory() {

    Inventory inventory = {};
    memset(&inventory, 0, sizeof(Inventory));


    inventory.maxCapacity = INVENTORY_CAPACITY;
    inventory.objects = malloc(sizeof(Object) * inventory.maxCapacity);
    for(int i=0 ; i<inventory.maxCapacity ; i++) {
        memset(&inventory.objects[i], 0, sizeof(Object)); // put all inventory slots to 0
    }


    // Add some items to the player's inventory
    Object sword = {1, "Wooden sword", 1, 10, {Weapon, 10, 1, 1, 0 , 0}};
    Object pickaxe = {2, "Wooden pickaxe", 1, 10, {Tool, 10, 0, 1, 0 , 0}};
    Object billhook = {3, "Wooden billhook", 1, 10 ,{Tool, 10, 0, 1, 0 , 0}};
    Object axe = {4, "Wooden axe", 1, 10, {Tool, 10, 0, 1, 0 , 0}};

    inventory.objects[0] = sword; // Wooden sword
    inventory.objects[1] = pickaxe; // Wooden pickaxe
    inventory.objects[2] = billhook; // Wooden billhook
    inventory.objects[3] = axe; // Wooden axe

    return inventory;
}


// Display the player's inventory
void display_inventory(Inventory inventory) {
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