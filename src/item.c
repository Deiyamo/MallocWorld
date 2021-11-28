//
// Created by TimTim on 01/11/2021.
//

#include "item.h"
#include "events.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



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

// Decrease the durability of the tool
Inventory decreaseItemDurability(Inventory inventory, int toolId, int casePosition) {
    int durabilityUsed = checkItemDurability(casePosition);

    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id == toolId && inventory.item[i].durability >= durabilityUsed) {
            inventory.item[i].durability -= durabilityUsed;
            return inventory;
        }
    }
    return inventory;
}


// REPAIR ITEM
// Check if an Item is repairable
int isItemRepairable(Item item) {
    if (item.property.type == Weapon || item.property.type == Tool) {
        return 1;
    }
    return 0;
}

// Repair the item in parameter (set durability as durability_max)
Item repairItem(Item item) {
    item.durability = item.property.durability_max;

    return item;
}


/*
 *   Get case position of the item to harvest.
 *   Go to the case Position as the line number, cause the id starts at 3 til 11
 *   So the file has to begin to the line 4 (0, 1, 2, 3)
 *   Return item properties or NULL
 */
char** getItemPropertiesFromFile(Inventory inventory, int casePosition) {

    if (inventory.currentCapacity < inventory.maxCapacity) {

        FILE *fp;
        int lineNumber = 0;
        const char* separators = "{}"; // separators list
        fp = fopen("../resources/itemList", "r");

        char** properties = malloc(sizeof(char*) * 10);

        char line[90]; // maximum line size !
        if (fp != NULL) {
            while (fgets(line, sizeof line, fp) != NULL) {
                if (lineNumber == casePosition) {
                    //printf("%s\n", line);

                    char* strToken = strtok(line, separators);
                    int j = 0;
                    while (strToken != NULL) {
                        properties[j] = malloc(sizeof(char) * 15);
                        strcpy(properties[j], strToken); // insert all properties of the item in an array.

                        strToken = strtok(NULL, separators);
                        j++;
                    }
                    break;
                }
                lineNumber++;
            }
            fclose(fp);

            return properties;

        } else {
            printf("/!\\ Error while opening itemList file...");
        }
    } else {
        printf("Your inventory is full, you can't take more items.");
    }

    return NULL;
}



// Display the craftable items from "craftList"
void displayCraftableItems(Game* game) {
    if (game->player.inventory.currentCapacity < game->player.inventory.maxCapacity) {
        FILE *fp;
        const char* separators = "{}"; // separators list
        fp = fopen("../resources/craftList", "r");

        char line[90]; // maximum line size !
        int lineNumber = 1;

        if (fp != NULL) {
            fgets(line, sizeof line, fp);
            displayColumnsName(line, separators);
            fgets(line, sizeof line, fp);
            fgets(line, sizeof line, fp);
            while (fgets(line, sizeof line, fp) != NULL) {

                printf("%3d - ", lineNumber);
                displayItemName(line, separators);

                printf("\n");
                lineNumber++;
            }
            fclose(fp);
        } else {
            printf("/!\\ Error while opening craftList file...");
        }
    } else {
        printf("Your inventory is full. Please store one item from your inventory to the storage, before craft a new one.");
    }
}

// Display items name
void displayItemName(char* line, const char* separators) {
    char** columnName = malloc(sizeof(char*) * 10);
    char* strToken = strtok(line, separators);

    for (int j = 0 ; strToken != NULL ; j++) {
        columnName[j] = malloc(sizeof(char) * 20);
        strcpy(columnName[j], strToken);

        strToken = strtok(NULL, separators);
    }
    printf("%s", columnName[1]);

    for (int j = 0; j < 10; j++) {
        free(columnName[j]);
    }
    free(columnName);
}


/* Verify if player can craft this Item
 *  Required items to craft selected item
 *  3 weapons, 1 armor MAX
 *  Check if the npc is in the right zone
 */
void verifyItemSelected(Game* game, int itemId) {

    //checkIfPlayerHasRequiredItems(itemId);
    //getchar();
    //getItemPropertiesFromFile();
    /*FILE *fp;
    const char* separators = "{}"; // separators list
    fp = fopen("../resources/craftList", "r");

    char** properties = malloc(sizeof(char*) * 10);
    char line[90]; // maximum line size !
    int lineNumber = 0;

    if (fp != NULL) {
        fgets(line, sizeof line, fp);
        fgets(line, sizeof line, fp);
        fgets(line, sizeof line, fp);
        while (fgets(line, sizeof line, fp) != NULL) {
            if (lineNumber == itemId) {
                char* strToken = strtok(line, separators);

                for (int j = 0; strToken != NULL ; j++) {
                    properties[j] = malloc(sizeof(char) * 15);
                    strcpy(properties[j], strToken); // insert all properties of the item in an array.

                    strToken = strtok(NULL, separators);
                }
                break;
            }
            lineNumber++;
        }
        fclose(fp);

        for (int i = 0; i < 10; i++) {
            printf("%s ", properties[i]);
        }

    } else {
        printf("/!\\ Error while opening itemList file...");
    }

    char playerStrChoice[5];
    long playerChoice = 0;
    while (playerChoice != -1) {
        fgets(playerStrChoice, 5, stdin);
        playerChoice = strtol(playerStrChoice, NULL, 0);
    }*/
}


char** getCraftFromFile(char* fileName, const char* separators, int itemId) {
    FILE *fp;
    fp = fopen(fileName, "r");

    if (fp != NULL) {
        char** properties = malloc(sizeof(char*) * 4);
        char line[90]; // maximum line size !
        int lineNumber = 0; // counter

        fgets(line, sizeof line, fp);
        fgets(line, sizeof line, fp);
        while (fgets(line, sizeof line, fp) != NULL) {
            if (lineNumber == itemId) {
                printf("%s", line);
                char* strToken = strtok(line, separators);
                for (int j = 0; strToken != NULL ; j++) {
                    properties[j] = malloc(sizeof(char) * 20);
                    strcpy(properties[j], strToken); // insert all properties of the item in an array.

                    strToken = strtok(NULL, separators);
                }
                break;
            }
            lineNumber++;
        }
        fclose(fp);
        return properties;

    } else {
        printf("/!\\ Error while opening itemList file...");
    }
    return NULL;
}


// Separate craft properties 1 by 1
char** getCraftItems(char* itemString, const char* separators) {

    char** items = malloc(sizeof(char*) * 4);
    char* strToken = strtok(itemString, separators);
    for (int j = 0; strToken != NULL ; j++) {
        items[j] = malloc(sizeof(char) * 15);
        strcpy(items[j], strToken); // insert all properties of the item in an array.

        strToken = strtok(NULL, separators);
    }

    return items;
}
char** getCraftZones(char* itemString, const char* separators) {

    char** zones = malloc(sizeof(char*) * 4);
    char* strToken = strtok(itemString, separators);
    for (int j = 0; strToken != NULL ; j++) {
        zones[j] = malloc(sizeof(char) * 4);
        strcpy(zones[j], strToken); // insert all properties of the item in an array.

        strToken = strtok(NULL, separators);
    }

    return zones;
}

void checkIfPlayerHasRequiredItems(int itemId) {
    char** properties = getCraftFromFile("../resources/craftSchema", "{}", itemId);
    if (properties != NULL) {
        char** items = getCraftItems(properties[1], ";");
        char** zones = getCraftZones(properties[2], ";");
        for (int i = 0; i < 3; i++) {
            if (items[i] != NULL) {
                printf("%s ", items[i]);
            }
            printf("\n");
        }
        for (int i = 0; i < 3; i++) {
            if (zones[i] != NULL) {
                printf("%s ", zones[i]);
            }
            printf("\n");
        }
        printf("%s %s %s\n", items[0], items[1], items[2]);
        printf("%s %s %s\n", zones[0], zones[1], zones[2]);
        /*for (int i = 0; i < 3; i++) {
            if (properties[i] != NULL) {
                free(properties[i]);
            }
            if (items[i] != NULL) {
                free(items[i]);
            }
            if (zones[i] != NULL) {
                free(zones[i]);
            }
        }
        free(properties);
        free(items);
        free(zones);*/

    }
}