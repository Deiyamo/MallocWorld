//
// Created by TimTim on 23/10/2021.
//

#include "map.h"
#include <stdio.h>
#include <stdlib.h>

// point.c
#include "npc.h"
#include "player.h"


// a struct containing the map
typedef struct Map {
    int** painting;
    int rows;
    int columns;
} Map;



int mapArray[ROWS][COLUMNS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0},
        {0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0},
        {4, 0, 0, 0, 0, 4, 3, 0, 0, 0, 2, 3, 0, 0, 0},
        {4, 4, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 2, 0, 0, 0, -1, 0, 0, 0, 0, 12, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 12, 12, 0},
        {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 12, 0},
        {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0}
};

void createMap() {
    Map map = {};

    map.painting = malloc(sizeof(int) * ROWS);
    for(int i=0 ; i<ROWS ; i++) {
        map.painting[i] = malloc(sizeof(int) * COLUMNS);
    }

    map.rows = ROWS;
    map.columns = COLUMNS;
}

void defaultMap() {
    //printf("%d %d \n", map.rows, map.columns);

    /*for (int i = 0; i < map.rows; i++) {
        for (int j = 0; j < map.columns; j++) {
            map.painting[i][j] = 0;

            printf("%d " , map.painting[i][j]);
        }
        printf("\n");
    }*/

}


void displayMap() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%3d", mapArray[i][j]);
//            printf("%d " , map.painting[i][j]);
        }
        printf("\n");
    }
}





/*------------------------------------------------------
     WILL GO TOP THE POINT.C LATER
------------------------------------------------------*/

// Check is future position is a portal, a monster, a walkable position, etc...
int checkFuturePosition(Game* game, int x, int y) {

    // Check map borders
    if (x < 0 || y < 0 || x >= ROWS || y >= COLUMNS) {
        return 0;
    }

    // Position is a monster
    if (mapArray[y][x] >= 12 && mapArray[y][x] <= 98) {
        // start the fight with a monster
    }
    // Position is a portal
    if (mapArray[y][x] == -2 || mapArray[y][x] == -3) {
        // teleport the player
        //teleportPlayer(portalType, currentZone); --> mapArray[y][x] , player zone
        printf("Do you want to go to the next/precedent zone\n");
        getchar();
    }

    switch (mapArray[y][x]) {
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
            harvestRock(game, mapArray[y][x]); // has to return a 1 to move or a 0 !!
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


int isPositionWalkable(int x, int y) { // Not used anymore !! see --> checkFuturePosition
    // Check map borders
    if (x < 0 || y < 0 || x >= ROWS || y >= COLUMNS) {
        return 0;
    }
    return mapArray[y][x] == 0 || mapArray[y][x] == -2 || mapArray[y][x] == -3;
}

// Set player's position on his structure
Point getPlayerPosition() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (mapArray[i][j] == 1) {
                Point position = {};
                position.X = j;
                position.Y = i;
                return position;
            }
        }
    }
}

void updatePlayerPositionOnMap(Point position, int newX, int newY) {
    // reset last position
    //printf("\n%d %d = %d\n", position.X, position.Y, mapArray[position.X][position.Y]);
    mapArray[position.Y][position.X] = 0;


    // update new position
    //printf("\n%d %d = %d\n", newX, newY, mapArray[newX][newY]);
    mapArray[newY][newX] = 1;

}

Point updatePlayerPosition(Point position, int newX, int newY) {
    position.X = newX;
    position.Y = newY;

    return position;
}