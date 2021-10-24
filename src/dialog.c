//
// Created by TimTim on 23/10/2021.
//

#include "dialog.h"
#include <stdio.h>
#include "events.h"


void displayGameTitle() {
    printf("\n   _____         .__  .__                   __      __            .__       .___\n"
           "  /     \\ _____  |  | |  |   ____   ____   /  \\    /  \\___________|  |    __| _/\n"
           " /  \\ /  \\\\__  \\ |  | |  |  /  _ \\_/ ___\\  \\   \\/\\/   /  _ \\_  __ \\  |   / __ |\n"
           "/    Y    \\/ __ \\|  |_|  |_(  <_> )  \\___   \\        (  <_> )  | \\/  |__/ /_/ |\n"
           "\\____|__  (____  /____/____/\\____/ \\___  >   \\__/\\  / \\____/|__|  |____/\\____ |\n"
           "        \\/     \\/                      \\/         \\/                         \\/\n");

    printf("\n\n");
}

void displayMenu() {
    displayGameTitle();

    printf("1) New game \n");
    printf("2) Load game\n");
    printf("3) Controls\n");
    printf("4) Items\n");
    printf("5) Exit\n");
    printf(":");
}


void displayControls() {
    clear_screen();

    printf("\n\t\tControls\n\n");
    printf("  z - move up\n"
           "  q - move left\n"
           "  s - move down\n"
           "  d - move right\n"
           "  (you can use the arrow keys too)\n\n"
           "  p - pause the game\n\n\n\n"
           "  press enter to go back to the menu...\n");

    int enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    clear_screen();
}