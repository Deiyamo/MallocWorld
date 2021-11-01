//
// Created by TimTim on 23/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "player.h"
#include "events.h"
#include "map.h"
#include "dialog.h"
#include "npc.h"
#include "inventory.h"



void run() {
    clear_screen();

    Game* game = malloc( sizeof(Game) );
    game->player = newPlayer();
    game->npc = newNpc();



    int playerChoice;
    do {
        clear_screen();
        // Display the player's position
        //displayPlayerPosition(game->player.position);

        // Display the map
        displayMap();
        // Display player's inventory
        displayInventoryFromMaxCapacity(game->player.inventory);
        // Display actions that the player can do
        displayPlayerMenu();


        // Switch (player's actions)
        playerChoice = handlePlayerInput(game);

    } while(playerChoice != '3');

}


int handlePlayerInput(Game* game) {
    int playerChoice = getchar();
    getchar();

    switch(playerChoice) {
        case 'z': // Move up
            printf("Moving up\n");
            if ( checkFuturePosition(game, game->player.position.X, game->player.position.Y - 1) ) {
                updatePlayerPositionOnMap(game->player.position, game->player.position.X, game->player.position.Y - 1);

                game->player.position = updatePlayerPosition(game->player.position, game->player.position.X, game->player.position.Y - 1);
            }

            break;

        case 'q': // Move left
            printf("Moving left\n");
            if ( checkFuturePosition(game, game->player.position.X - 1, game->player.position.Y) ) {
                updatePlayerPositionOnMap(game->player.position, game->player.position.X - 1, game->player.position.Y);

                game->player.position = updatePlayerPosition(game->player.position, game->player.position.X - 1, game->player.position.Y);
            }
            break;

        case 's': // Move down
            printf("Moving down\n");
            if ( checkFuturePosition(game, game->player.position.X, game->player.position.Y + 1) ) {
                updatePlayerPositionOnMap(game->player.position, game->player.position.X, game->player.position.Y + 1);

                game->player.position = updatePlayerPosition(game->player.position, game->player.position.X, game->player.position.Y + 1);
            }
            break;

        case 'd': // Move right
            printf("Moving right\n");
            if ( checkFuturePosition(game, game->player.position.X + 1, game->player.position.Y) ) {
                updatePlayerPositionOnMap(game->player.position, game->player.position.X + 1, game->player.position.Y);

                game->player.position = updatePlayerPosition(game->player.position, game->player.position.X + 1, game->player.position.Y);
            }
            break;

        case 'i':
            displayInventoryMenu(game->player.inventory);
            break;

        case 'p': // Pause menu
            displayPauseMenu();
            playerChoice = getchar();
            getchar();

            if (playerChoice == '2') { // Save choice
                printf("Saving game...\n");
            }
            break;

        default:
            printf("This value is not a choice... Please try again");
            break;
    }

    return playerChoice;
}




void kill_game() {
    kill_player();
}