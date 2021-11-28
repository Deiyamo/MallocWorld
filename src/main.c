#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "game.h"
#include "dialog.h"

/*
   _____         .__  .__                   __      __            .__       .___
  /     \ _____  |  | |  |   ____   ____   /  \    /  \___________|  |    __| _/
 /  \ /  \\__  \ |  | |  |  /  _ \_/ ___\  \   \/\/   /  _ \_  __ \  |   / __ |
/    Y    \/ __ \|  |_|  |_(  <_> )  \___   \        (  <_> )  | \/  |__/ /_/ |
\____|__  (____  /____/____/\____/ \___  >   \__/\  / \____/|__|  |____/\____ |
        \/     \/                      \/         \/                         \/
*/

int main(int argc, char **argv) {

    runMain();

    /* int choice;

    do {
        displayMenu(); // Display the text menu
        choice = getchar();
        getchar();

        switch(choice) {
            case '1': // New game
                //createMap();
                run();

                break;

            case '2': // Load game
                printf("Load game from save\n");
                break;

            case '3': // Display controls
                displayControls();
                break;

            case '4': // Display the list of all items (maybe une fonction de tri par type)
                printf("List of all items\n");
                break;

            case '5': // Exit
                printf("\nSee you soon !\n");
                exit(0); // terminates the complete program execution

            default:
                printf("This value is not a choice... Please try again\n");
                break;
        }

    } while(1); */


    // SAVE GAME
        //const char * fileName = "save.log";
        //create_saveFile(fileName);


    return 0;
}
