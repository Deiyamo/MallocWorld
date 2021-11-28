//
// Created by TimTim on 23/10/2021.
//

#include "events.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "map.h"


// Clear the screen
void clear_screen() {
    system("cls||clear");
}


// Clear screen and display the map
void restore_screen() {
    clear_screen();
    displayMap();
}

/*void getcharAdvanced(void) {
    int enter;

    do {
        enter = getchar();
    } while (enter != '\n' && enter != '\r');
}*/



// Display columns name
void displayColumnsName(char* line, const char* separators) {
    char** columnName = malloc(sizeof(char*) * 10);
    char* strToken = strtok(line, separators);

    for (int j = 0 ; strToken != NULL ; j++) {
        columnName[j] = malloc(sizeof(char) * 15);
        strcpy(columnName[j], strToken);

        strToken = strtok(NULL, separators);
    }
    printf("%3s   ", columnName[0]);
    printf("%s", columnName[1]);

    for (int j = 0; j < 10; j++) {
        free(columnName[j]);
    }
    free(columnName);

    printf("\n\n");
}