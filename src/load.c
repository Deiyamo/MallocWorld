//
// Created by eserban on 22/11/2021.
//


#include "load.h"

void createZones(Map **map, char* filePath) {
    char buffer[100];

    FILE *loadFile = fopen(filePath, "r+");

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

Game *load() {
    Game *game = malloc(sizeof(Game));
    game->map = malloc(sizeof(Map*)*3);
    for (int i = 0; i < 3; ++i) {
        game->map[i] = malloc(sizeof(Map));
    }
    char mapName[100], playerName[100];
    sprintf(mapName, "%s/MAP.log", LOAD_DIR_PATH);
    sprintf(playerName, "%s/PLAYER.log", LOAD_DIR_PATH);
    FILE *f = fopen(playerName, "r");
    if  (f != NULL) {

        game->player = loadPlayer(f);
        game->npc = newNpc();

        createZones(game->map, mapName);

    } else {
        printf("Ce fichier n'existe aps !!! \n");
    }


    return game;
}

Player loadPlayer(FILE *f) {
    Player player;
    char buffer[100], *ptr;
    char currentLine[20];
    char delimiter[] = "{}/";
    //SKIP -- PLAYER --
    fgets(buffer, 100, f);
    //Get NAME AND CURRENT MAP
    fgets(currentLine, 20, f);
    ptr = strtok(currentLine, delimiter);
    if  (ptr!=NULL){
        player.name = malloc(sizeof(char)*(strlen(ptr)+1));
        sprintf(player.name, "%s", ptr);
        ptr = strtok(NULL, delimiter);
    }
    player.currentMap = atoi(ptr);
    ptr = strtok(NULL, delimiter);
    //GET LEVEl
    fgets(currentLine, 20, f);
    ptr = strtok(currentLine, delimiter);
    if  (ptr!=NULL) {
        player.level.floor = atoi(ptr);
        ptr = strtok(NULL, delimiter);
    }
    //GET CURRENT XP AND NEXT XP
    fgets(currentLine, 20, f);
    ptr = strtok(currentLine, delimiter);
    if  (ptr!=NULL) {
        player.level.XPcurrent = atoi(ptr);
        ptr = strtok(NULL, delimiter);
    }
    player.level.XPmax = atoi(ptr);
    ptr = strtok(NULL, delimiter);
    //GET HP CURRENT et HP MAX
    fgets(currentLine, 20, f);
    ptr = strtok(currentLine, delimiter);
    if  (ptr!=NULL) {
        player.health.HPcurrent = atoi(ptr);
        ptr = strtok(NULL, delimiter);
    }
    player.health.HPmax = atoi(ptr);
    ptr = strtok(NULL, delimiter);


    player.inventory = starting_inventory();

    return player;
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
