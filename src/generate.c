//
// Created by eserban on 22/11/2021.
//

#include "generate.h"

void generateMonsters(Map *map) {
    int countMonsters = 0, randYNum, randXNum;
    while (countMonsters < NB_MONSTERS_MIN){
        for (int x = 0; x < ROWS; ++x) {
            for (int y = 0; y < COLUMNS; ++y) {
                randYNum = rand()%COLUMNS;
                randXNum = rand()%ROWS;
                if(x == randXNum && y == randYNum && map->painting[x][y] == 0) {
                    map->painting[x][y] = (rand()%(98-12))+12;
                    countMonsters++;
                }
            }
        }
    }
}

void generateRocks(Map *map) {
    int countRocks = 0, randYNum, randXNum;
    while (countRocks < NB_ROCKS_MIN){
        for (int x = 0; x < ROWS; ++x) {
            for (int y = 0; y < COLUMNS; ++y) {
                randYNum = rand()%COLUMNS;
                randXNum = rand()%ROWS;
                if(x == randXNum && y == randYNum && map->painting[x][y] == 0) {
                    switch (map->type) {
                        case 0:
                            map->painting[x][y] = 4;
                            break;
                        case 1:
                            map->painting[x][y] = 7;
                            break;
                        case 2:
                            map->painting[x][y] = 10;
                            break;
                    }
                    countRocks++;
                }
            }
        }
    }
}

void generatePlants(Map *map) {
    int countPlants = 0, randYNum, randXNum;
    while (countPlants < NB_PLANTS_MIN) {
        for (int x = 0; x < ROWS; ++x) {
            for (int y = 0; y < COLUMNS; ++y) {
                randYNum = rand() % COLUMNS;
                randXNum = rand() % ROWS;
                if (x == randXNum && y == randYNum && map->painting[x][y] == 0) {
                    switch (map->type) {
                        case 0:
                            map->painting[x][y] = 3;
                            break;
                        case 1:
                            map->painting[x][y] = 6;
                            break;
                        case 2:
                            map->painting[x][y] = 9;
                            break;
                    }
                    countPlants++;
                }
            }
        }
    }
}

void generateTrees(Map *map) {
    int countTrees = 0, randYNum, randXNum;
    while (countTrees < NB_TREES_MIN){
        for (int x = 0; x < ROWS; ++x) {
            for (int y = 0; y < COLUMNS; ++y) {
                randYNum = rand()%COLUMNS;
                randXNum = rand()%ROWS;
                if(x == randXNum && y == randYNum && map->painting[x][y] == 0) {
                    switch (map->type) {
                        case 0:
                            map->painting[x][y] = 5;
                            break;
                        case 1:
                            map->painting[x][y] = 8;
                            break;
                        case 2:
                            map->painting[x][y] = 11;
                            break;
                    }
                    countTrees++;
                }
            }
        }
    }
}

void placePlayer(Map *map) {
    int randX = rand()%ROWS;
    int randY = rand()%COLUMNS;
    while  (map->painting[randX][randY] != 0){
        randX = rand()%ROWS;
        randY = rand()%COLUMNS;
    }
    map->painting[randX][randY] = 1;
}

void placePNJ(Map *map) {
    int randX = rand()%ROWS;
    int randY = rand()%COLUMNS;
    while  (map->painting[randX][randY] != 0){
        randX = rand()%ROWS;
        randY = rand()%COLUMNS;
    }
    map->painting[randX][randY] = 2;
}

void placePortal(Map *map) {
    int randX = rand()%ROWS;
    int randY = rand()%COLUMNS;
    while  (map->painting[randX][randY] != 0){
        randX = rand()%ROWS;
        randY = rand()%COLUMNS;
    }
    switch (map->type) {
        case 0:
            map->painting[randX][randY] = -2;
            break;
        case 1:
            map->painting[randX][randY] = -2;
            randX = rand()%ROWS;
            randY = rand()%COLUMNS;
            while  (map->painting[randX][randY] != 0){
                randX = rand()%ROWS;
                randY = rand()%COLUMNS;
            }
            map->painting[randX][randY] = -3;
            break;
        case 2:
            map->painting[randX][randY] = -3;
            break;
    }
}

void placeWalls(Map *map) {
    int countWalls = 0, randYNum, randXNum;
    while (countWalls < NB_WALLS) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLUMNS; ++j) {
                randYNum = rand() % COLUMNS;
                randXNum = rand() % ROWS;
                if (i == randXNum && j == randYNum && map->painting[i][j] == 0) {
                    map->painting[i][j] = -1;
                    countWalls ++;
                }
            }
        }
    }
}

Map **generate() {
    srand( time( NULL ) );
    Map **result = malloc(sizeof(Map*)*3);
    for (int i = 0; i < 3; ++i) {
        result[i] = malloc(sizeof(Map));
        initMap(result[i], i);
        generateMonsters(result[i]);
        generateRocks(result[i]);
        generatePlants(result[i]);
        generateTrees(result[i]);
        placePlayer(result[i]);
        placePNJ(result[i]);
        placePortal(result[i]);
        placeWalls(result[i]);
//        displayMap(result[i]);
    }
    return result;
}