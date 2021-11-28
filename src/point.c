//
// Created by TimTim on 30/10/2021.
//

#include <stdio.h>
#include "point.h"


/*void isPositionWalkable(int x, int y) {
    //mapArray[x][y] = 11;
    displayMap();

    //return Point[x][y] == '0' || Point[x][y] == '-1';
}*/


// The player goes to another map
Game teleportPlayer(Game* game, int portalType, int currentMap) {
    if (portalType == -2 && currentMap == 0) { // zone 1 --> 2
        if (game->player.level.floor >= 3) {
            game->player.currentMap = 1;
        } else {
            printf("Please level up until your level 3 before accessing to the next zone.");
        }
    } else if (portalType == -2 && currentMap == 1) { // zone 2 --> 1
        game->player.currentMap = 0;
    } else if (portalType == -3 && currentMap == 1) { // zone 2 --> 3
        if (game->player.level.floor >= 7) {
            game->player.currentMap = 2;
        } else {
            printf("Please level up until your level 7 before accessing to the next zone.");
        }
    } else if (portalType == -3 && currentMap == 2) { // zone 3 --> 2
        game->player.currentMap = 1;
    }

    return *game;
}
