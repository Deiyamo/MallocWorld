//
// Created by TimTim on 17/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "save.h"
#include "inventory.h"
#define SAVEREPO "../saves/"

void saveMap(Map *map, FILE *f) {
    fprintf(f, "-- ZONE %d --\n", map->type+1);
    for (int j = 0; j < ROWS; ++j) {
        for (int k = 0; k < COLUMNS; ++k) {
            fprintf(f, "%d ", map->painting[j][k]);
        }
        fputs("\n", f);
    }
}


void savePlayer(Player player, FILE *f) {
    fprintf(f, "{%s}{%d}\n", player.name, player.currentMap);
    fprintf(f, "{%d}\n", player.level.floor);
    fprintf(f, "{%d}/{%d}\n", player.level.XPcurrent, player.level.XPmax);
    fprintf(f, "{%d}/{%d}\n", player.health.HPcurrent, player.health.HPmax);
    saveInventory(player.inventory, f);
}

void saveNpc(Npc npc, FILE *f) {
    fputs("-- STORAGE --\n", f);
    for (int i = 0; i < npc.storage.currentCapacity; ++i) {
        fprintf(f, "{%d}@{%d}\n", npc.storage.item[i].quantity, npc.storage.item[i].id);
    }
}

void saveInventory(Inventory inventory, FILE *f) {
    int emptySlotsSize;

    fputs("-- INVENTORY --\n", f);
    for (int i = 0; i < inventory.currentCapacity; ++i) {
        fprintf(f, "{%d}@{%d}@{%d}\n", inventory.item[i].quantity, inventory.item[i].id, inventory.item[i].durability);
    }
    emptySlotsSize = inventory.maxCapacity - inventory.currentCapacity;
    for (int i = 0; i < emptySlotsSize; ++i) {
        fputs("{0}@{0}@{0}\n", f);
    }
}

void saveGame(Game *game) {
    char mapDirName[100], playerDirName[100];
    sprintf(mapDirName, "%s/MAP.log", SAVEREPO);
    sprintf(playerDirName, "%s/PLAYER.log", SAVEREPO);

    FILE *f = fopen(mapDirName, "w");
    if  (f != NULL) {
        fputs("=== MAP ===\n", f);

        for (int i = 0; i < 3; ++i) {
            saveMap(game->map[i], f);
        }
        fclose(f);
        f = fopen(playerDirName, "w");
        if(f != NULL) {
            fputs("=== PLAYER ===\n", f);
            savePlayer(game->player, f);
            saveNpc(game->npc, f);
            fclose(f);
        } else {
            printf("Le fichier de sauvegarde n'éxiste pas !!! \n");
        }
    } else {
        printf("Le fichier de sauvegarde n'éxiste pas !!! \n");
    }
    
}
