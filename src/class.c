//
// Created by TimTim on 07/11/2021.
//

#include "class.h"
#include "dialog.h"
#include "item.h"
#include <string.h>
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
           item.name, item.durability, item.property.durability_max);
}
void displayCraft(Item item) {
    printf("[%s]x%d",
           item.name, item.quantity);
}
void displayArmor(Item item) {
    printf("[%s] (%d/%d) - +%d Armor",
           item.name, item.durability, item.property.durability_max, item.property.resistance);
}
void displayHeal(Item item) {
    printf("[%s]x%d (%d/%d) - +%d Heal Point",
           item.name, item.quantity, item.durability, item.property.durability_max, item.property.heal);
}

// Return the enum value instead of a string
Class stringToEnum(const char* itemType) {
    if (strcmp(itemType, "Weapon") == 0) {
        return Weapon;
    } else if (strcmp(itemType, "Tool") == 0) {
        return Tool;
    } else if (strcmp(itemType, "Craft") == 0) {
        return Craft;
    } else if (strcmp(itemType, "Armor") == 0) {
        return Armor;
    } else if (strcmp(itemType, "Heal") == 0) {
        return Heal;
    }

    return -1;
}

// Check the zone of the rock (I, II or III) and then return the tool needed to harvest it.
int checkPickaxeToUse(Inventory inventory, int casePosition, int currentTool) {
    if (currentTool == 4) {
        if ( checkPickaxe(inventory, 2, checkItemDurability(casePosition)) ) { // Wooden pickaxe
            return 2;
        } else {
            checkPickaxeToUse(inventory, casePosition, 7);
        }
    } else if (currentTool == 7) {
        if ( checkPickaxe(inventory, 12, checkItemDurability(casePosition)) ) { // Stone pickaxe
            return 12;
        } else {
            checkPickaxeToUse(inventory, casePosition, 10);
        }
    } else if(currentTool == 10) {
        if ( checkPickaxe(inventory, 23, checkItemDurability(casePosition)) ) { // Iron pickaxe
            return 23;
        }
    }

    // The player hasn't the required equipment.
    noRequiredEquipment("Pickaxe");
    return 0;
}

// Check if the player has the required pickaxe and in good shape.
int checkPickaxe(Inventory inventory, int pickaxeId, int durabilityNeeded) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id == pickaxeId && inventory.item[i].durability >= durabilityNeeded) {
            return 1;
        }
    }
    return 0;
}
