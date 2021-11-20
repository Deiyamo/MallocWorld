//
// Created by TimTim on 01/11/2021.
//

#include "item.h"
#include <stdio.h>
#include <string.h>


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




// Check if the item durability is up or equal than necessary for harvesting.
int checkItemDurability(int casePosition) {
    int maxDurability = MAX_DURABILITY;

    if (casePosition == 3 || casePosition == 4 || casePosition == 5) {
        return (maxDurability * 10) / 100;
    } else if (casePosition == 6 || casePosition == 7 || casePosition == 8) {
        return (maxDurability * 20) / 100;
    } else if (casePosition == 9 || casePosition == 10 || casePosition == 11) {
        return (maxDurability * 40) / 100;
    }

    return 0;
}


/*
 *   Get case position of the item to harvest.
 *   Go to the case Position as the line number, cause the id starts at 3 til 11
 *   So the file has to begin to the line 4 (0, 1, 2, 3)
 */
Inventory addItemToInventory(Inventory inventory, int casePosition) { // item to add (id) and quantity !!

    if (inventory.currentCapacity < inventory.maxCapacity) {

        FILE *fp;
        int lineNumber = 0;
        const char* separators = "{}"; // separators list
        fp = fopen("../resources/itemList", "r");

        char line[90]; // maximum line size !
        if (fp != NULL) {
            char currentLine[90]; // maximum line size !
            while (fgets(currentLine, sizeof currentLine, fp) != NULL) {
                if (lineNumber == 1) {
                    printf("%s\n", currentLine);

                    char* strToken = strtok(currentLine, separators);
                    while (strToken != NULL) {
                        printf("%s\n", strToken);
                        strToken = strtok(NULL, separators);
                    }

                    break;
                }
                lineNumber++;
            }
            fclose(fp);
        } else {
            printf("/!\\ Error while opening itemList file...");
        }

        printf("%s", line);
        // {6}{Stone}{Quantity}{Durability}@{Craft}{Dur_Max}{Damage}{Stack}{Heal}{Resistance}

        //inventory.currentCapacity += 1;
        // insert new item to inventory
        /*for (int i = 1; i <= inventory.maxCapacity; ++i) {
            if (inventory.item[i].id == 0) {
                inventory.item[i].id = ; // itemToAdd
                inventory.item[i].name = ;
                inventory.item[i].quantity = ;
                inventory.item[i].durability = ;
                inventory.item[i].property.type = ;
                inventory.item[i].property.durability_max = ;
                inventory.item[i].property.damage = ;
                inventory.item[i].property.stack = ;
                inventory.item[i].property.heal = ;
                inventory.item[i].property.resistance = ;

                break; // quit loop after the item is inserted
            }
        }*/

    } else {
        printf("Your inventory is full, you cant take more items.");
    }

    getchar();

    return inventory;
}