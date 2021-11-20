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
    if ( checkPickaxeToUse(game->player.inventory, casePosition, casePosition) ) { // 1 or 0
        // add items to inventory
        char **properties = getItemPropertiesFromFile(game->player.inventory, casePosition); // get item properties from Itemlist

        // If inventory not full
        getchar();
        if (properties[0] != "-1") { // if return 1
            *game = addItemToInventory(game, properties);
        }

        free(properties);

        getchar();

        // decrease durability of tool
        // then move player by returning -1
        // careful to random !! It's not a real random !! TO FIX

    }

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