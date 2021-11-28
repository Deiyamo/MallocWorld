//
// Created by TimTim on 23/10/2021.
//

#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// point.c
#include "npc.h"
#include "player.h"

void initMap(Map *map, int type) {
    map->rows = ROWS;
    map->columns = COLUMNS;
    map->type = type;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            map->painting[i][j] = 0;
        }
    }
}


void displayMap(Game *game) {
    int currentMap = game->player.currentMap;
    printf("---------------------------------ZONE %d---------------------------------\n", game->map[currentMap]->type);
    for (int j = 0; j < game->map[currentMap]->rows; j++) {
        for (int k = 0; k < game->map[currentMap]->columns; k++) {
            printf("%3d", game->map[currentMap]->painting[j][k]);
        }
        printf("\n");
    }
}





/*------------------------------------------------------
     WILL GO TOP THE POINT.C LATER
------------------------------------------------------*/

// Check is future position is a portal, a monster, a walkable position, etc...

int checkFuturePosition(Game *game, int x, int y) {

    // Check map borders
    if (x < 0 || y < 0 || x >= ROWS || y >= COLUMNS) {
        return 0;
    }

    // Position is a monster
    if (game->map[game->player.currentMap]->painting[y][x] >= 12 && game->map[game->player.currentMap]->painting[y][x] <= 98) {
        // start the fight with a monster
    }
    // Position is a portal
    if (game->map[game->player.currentMap]->painting[y][x] == -2 || game->map[game->player.currentMap]->painting[y][x] == -3) {
        // teleport the player
        //teleportPlayer(portalType, currentZone); --> game->map[game->player.currentMap]->painting[y][x] , player zone
        printf("Do you want to go to the next/precedent zone\n");
        getchar();
    }

    switch (game->map[game->player.currentMap]->painting[y][x]) {
        case -1: // Position is a wall
            return 0;

        case 0: // Position is walkable
            return 1;

        case 1: // Position is a player
            printf("Ups there is another player here.\nDon't disturb him, he seems lost... poor thing\n");
            break;
        case 2: // Position is a npc
            *game = interactWithNpc(game);
            break;
        case 3: // Position a plant (1, 2 and 3)
        case 6:
        case 9:
            harvestPlant();
            break;
        case 4: // Position is a rock (1, 2 and 3)
        case 7:
        case 10:
            harvestRock(game,game->map[game->player.currentMap]->painting[y][x]); // has to return a 1 to move or a 0 !!
            break;
        case 5: // Position is a tree (1, 2 and 3)
        case 8:
        case 11:
            harvestTree();
            printf("Ouch this is a tree !\n");
            break;

        case 99:
            // Position is the end boss
            break;

        default:
            return 0;
    }

    return 0;
}


int isPositionWalkable(Map *map, int x, int y) { // Not used anymore !! see --> checkFuturePosition
    // Check map borders
    if (x < 0 || y < 0 || x >= ROWS || y >= COLUMNS) {
        return 0;
    }
    return map->painting[y][x] == 0 || map->painting[y][x] == -2 || map->painting[y][x] == -3;
}

// Set player's position on his structure
Point getPlayerPosition(Map *map) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (map->painting[i][j] == 1) {
                Point position;
                position.X = j;
                position.Y = i;
                return position;
            }
        }
    }
}

void updatePlayerPositionOnMap(Point position, int newX, int newY, Map *map) {
    // reset last position
    //printf("\n%d %d = %d\n", position.X, position.Y, mapArray[position.X][position.Y]);
    map->painting[position.Y][position.X] = 0;


    // update new position
    //printf("\n%d %d = %d\n", newX, newY, mapArray[newX][newY]);
    map->painting[newY][newX] = 1;

}

Point updatePlayerPosition(Point position, int newX, int newY) {
    position.X = newX;
    position.Y = newY;

    return position;
}