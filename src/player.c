//
// Created by TimTim on 23/10/2021.
//

#include "player.h"
#include "map.h"
#include "level.h"
#include "health.h"
#include "inventory.h"
#include "class.h"
#include "item.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Player newPlayer() {
    Player player = {};

    player.name = "Bob";
    player.level = set_level_to_zero();
    player.health = starting_health();
    player.inventory = starting_inventory();
    player.position = getPlayerPosition();

    return player;
}


void display_player(Player player) {
    printf("Nom du joueur : %s\n", player.name);
    printf("%dlvl %dxp %dxpMax\n", player.level.floor, player.level.XPcurrent, player.level.XPmax);
    printf("%dhp %dhpMax\n", player.health.HPcurrent, player.health.HPmax);
    printf("Inventaire cap. : %d\n", player.inventory.maxCapacity);

    displayInventoryFromMaxCapacity(player.inventory);
    displayPlayerPosition(player.position);
}

void displayPlayerPosition(Point position) {
    printf("{%d, %d}\n", position.X, position.Y);
}


/*------------------------------------------------------
    HARVEST AND COLLECT
------------------------------------------------------*/

int harvestPlant() {

}

int harvestRock(Game* game, int casePosition) {

    // If player has a pickaxe in good shape
    int toolId = checkPickaxeToUse(game->player.inventory, casePosition, casePosition);
    if ( toolId != 0 ) { // get the id of the pickaxe
        // Add items to inventory
        char **properties = getItemPropertiesFromFile(game->player.inventory, casePosition); // get item properties from Itemlist
        if (properties != NULL) { // if inventory not full
            printf("I'm in !");
            *game = addItemToInventory(game, properties);
            for(int i = 0; i < 10; i++) {
                free(properties[i]);
            }
            free(properties);

            // Decrease the tool durability
            game->player.inventory = decreaseItemDurability(game->player.inventory, toolId, casePosition);
        }


        getchar();

        printf("does it work ?");
        // then move player by returning -1
        // careful to random !! It's not a real random !! TO FIX
        // stack item when not 20 yet
        return 1;
    }

    return 0;
}

int harvestTree() {

}







void movePlayer() {}
void XPincrease_player() {}
void levelUp_player() {}


void kill_player() {
    // kill level
    // kill health
    // kill inventory
}