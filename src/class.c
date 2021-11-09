//
// Created by TimTim on 07/11/2021.
//

#include "class.h"
#include "dialog.h"
#include "item.h"


// Check the zone of the rock (I, II or III) and then return the tool needed to harvest it.
int checkPickaxeToUse(Inventory inventory, int casePosition, int currentTool) {
    if (currentTool == 4) {
        if ( checkPickaxe(inventory, 2, checkItemDurability(casePosition)) ) { // Wooden pickaxe
            return 1;
        } else {
            checkPickaxeToUse(inventory, casePosition, 7);
        }
    } else if (currentTool == 7) {
        if ( checkPickaxe(inventory, 12, checkItemDurability(casePosition)) ) { // Stone pickaxe
            return 1;
        } else {
            checkPickaxeToUse(inventory, casePosition, 10);
        }
    } else if(currentTool == 10) {
        if ( checkPickaxe(inventory, 23, checkItemDurability(casePosition)) ) { // Iron pickaxe
            return 1;
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
