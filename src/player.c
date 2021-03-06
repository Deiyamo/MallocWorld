//
// Created by TimTim on 23/10/2021.
//

#include "player.h"
#include "level.h"
#include "health.h"
#include "inventory.h"

#include <stdio.h>


Player new_player() {
    Player player = {};

    player.name = "Bob";
    player.level = set_level_to_zero();
    player.health = starting_health();
    player.inventory = starting_inventory();

    return player;
}


void display_player(Player player) {
    printf("Nom du joueur : %s\n", player.name);
    printf("%dlvl %dxp %dxpMax\n", player.level.floor, player.level.XPcurrent, player.level.XPmax);
    printf("%dhp %dhpMax\n", player.health.HPcurrent, player.health.HPmax);
    printf("Inventaire cap. : %d\n", player.inventory.maxCapacity);

    display_inventory(player.inventory);
}



void move_player() {

}


void XPincrease_player() {

}


void levelUp_player() {

}


void kill_player() {

}