//
// Created by TimTim on 01/11/2021.
//

#include "item.h"
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


/*
 *   Get case position of the item to harvest.
 *   Go to the case Position as the line number, cause the id starts at 3 til 11
 *   So the file has to begin to the line 4 (0, 1, 2, 3)
 *   Return item properties or "-1"
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
                    printf("%s\n", line);

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
            for (int i = 0; i < 10 ; ++i) {
                printf("%s\n", properties[i]);
            }

            return properties;

        } else {
            printf("/!\\ Error while opening itemList file...");
        }
    } else {
        printf("Your inventory is full, you cant take more items.");
    }

    return NULL;
}