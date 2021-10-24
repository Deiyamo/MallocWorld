//
// Created by TimTim on 23/10/2021.
//

#include "game.h"
#include "player.h"
#include "inventory.h"
#include "events.h"
#include "map.h"


void kill_game() {
    kill_player();
}

void run() {
    clear_screen();

    GAME game = {};

    game.player = new_player();

    // Display the map
    displayMap();
    // Display player's info
    display_player(game.player);

}



