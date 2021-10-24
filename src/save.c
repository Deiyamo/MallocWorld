//
// Created by TimTim on 17/10/2021.
//

#include <stdio.h>
#include <string.h>
#include "save.h"


void create_saveFile(const char *fileName) {
    FILE *fp;

    char destRepo[] = "../saves/";
    strcat(destRepo, fileName);

    fp = fopen(destRepo, "w");

    if (fp != NULL) {
        printf("Sauvegarde en cours....");

        fprintf(fp, "=== MAP ===\n");

        // Zone 1
        fprintf(fp, "-- ZONE 1 --\n");

        // Zone 2
        fprintf(fp, "-- ZONE 2 --\n");

        // Zone 3
        fprintf(fp, "-- ZONE 3 --\n");


        fclose(fp);
    } else {
        printf("Erreur lors de la sauvegarde du jeu !");
    }

}
