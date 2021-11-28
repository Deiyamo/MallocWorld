//
// Created by TimTim on 23/10/2021.
//

#include "events.h"
#include <stdlib.h>

#include "map.h"


// Clear the screen
void clear_screen() {
    system("cls||clear");
}


// Clear screen and display the map
void restore_screen(Game *game) {
    clear_screen();
    displayMap(game);
}
