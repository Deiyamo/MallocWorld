//
// Created by eserban on 22/11/2021.
//


#include "load.h"

void createZones(Map **map) {
    char buffer[100];

    FILE *loadFile = fopen(MAP_LOAD_FILE_PATH, "r+");

    //SKIP === MAP ===
    fgets(buffer, 100, loadFile);

    for (int i = 0; i < 3; ++i) {
        //SKIP -- ZONE i --
        fgets(buffer, 100, loadFile);
        initMap(map[i], i);
        loadMap(map[i], loadFile);
    }

    fclose(loadFile);
}

Map** load() {
    Map **map = malloc(sizeof(Map*)*3);
    for (int i = 0; i < 3; ++i) {
        map[i] = malloc(sizeof(Map));
    }

    createZones(map);
    return map;
}

void loadMap(Map *map, FILE *mapFile) {
    char currentLine[COLUMNS*3];
    char delimiter[] = " ";
    char* ptr;
    int count;
    for (int i = 0; i < ROWS; ++i) {
        count = 0;
        fgets(currentLine, 100, mapFile);
        ptr = strtok(currentLine, delimiter);
        while(ptr != NULL)
        {
            map->painting[i][count] = atoi(ptr);
            ptr = strtok(NULL, delimiter);
            count++;
        }
    }
}
