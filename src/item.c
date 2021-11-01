//
// Created by TimTim on 01/11/2021.
//

#include "item.h"
#include <stdio.h>


// Check the type of the item for display it
void checkItemTypeForDisplay(Item item) {
    if (item.property.type == Weapon) {
        displayWeapon(item);
    } else if (item.property.type == Tool) {
        displayTool(item);
    } else if (item.property.type == Craft) {
        displayCraft(item);
    } else if (item.property.type == Armor) {
        displayArmor(item);
    } else if (item.property.type == Heal) {
        displayHeal(item);
    }
}

void displayWeapon(Item item) {
    printf("[%s] (%d/%d) - %d Attack Damage",
           item.name, item.durability, item.property.durability_max, item.property.damage);
}
void displayTool(Item item) {
    printf("[%s] (%d/%d)",
           item.name, item.durability, item.property.durability_max, item.property.damage);
}
void displayCraft(Item item) {
    printf("[%s]x%d (%d/%d)",
           item.name, item.quantity, item.durability, item.property.durability_max);
}
void displayArmor(Item item) {
    printf("[%s] (%d/%d) - +%d Armor",
           item.name, item.durability, item.property.durability_max, item.property.resistance);
}
void displayHeal(Item item) {
    printf("[%s]x%d (%d/%d) - +%d Heal Point",
           item.name, item.quantity, item.durability, item.property.durability_max, item.property.heal);
}