//
// Created by TimTim on 23/10/2021.
//

#include "player.h"
#include "map.h"
#include "level.h"
#include "health.h"
#include "inventory.h"
#include "fight.h"
#include "monster.h"
#include "game.h"
#include "events.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STARTING_XP 100


Player newPlayer() {
    Player player = {};

    Item sword = {1, "Wooden sword", 1, 10, {Weapon, 10, 3, 1, 0 , 0}};

    player.name = "Sponge Bob";
    player.level = setLevelToZero();
    player.maxXp = STARTING_XP;
    player.health = starting_health(100,100);
    player.inventory = starting_inventory();
    player.position = getPlayerPosition();
    player.hands = sword;

    return player;
}

/* Affichage du joueur */
void displayPlayer(Player *player) {
    printf("\nPlayer : %s\n", player->name);
    printf("Lvl : %d\n", player->level.floor);
    printf("%d / %d XP\n", player->level.XpCurrent, player->level.XpMax);
    printf("%d / %d HP\n", player->health.HPcurrent, player->health.HPmax);
    printf("Inventaire cap. : %d\n", player->inventory.maxCapacity);

    displayInventoryFromMaxCapacity(player->inventory);
    displayPlayerPosition(player->position);
}

/* Affichage du joueur pendant le combat */
void displayPlayerFight(Fight *fight) {
    printf("\nPlayer : %s\n", fight->player->name);
    printf("Lvl : %d\n", fight->player->level.floor);
    printf("%d / %d HP\n", fight->player->health.HPcurrent, fight->player->health.HPmax);
    printf("%d / %d XP\n", fight->player->level.XpCurrent, fight->player->level.XpMax);
}

/* Affichage de la postion du joueur */
void displayPlayerPosition(Point position) {
    printf("\n Tu es en position : {%d, %d}\n", position.X, position.Y);
}

/*------------------------------------------------------
    Nicolas update
------------------------------------------------------*/

/* Affichage des actions possibles du joueur pendant un combat */
void displayInteractionPlayer(Fight *fight) {
    printf("\n\n");
    printf("Player action: \n 2. Attack \n 3. Potion \n 4. Escape \n\n");
    printf("Press the action you want to do : ");

    int action = 0;
    do{
        action = getchar();
        switch (action)
        {
        case '2':
            actionPlayer(fight, 2);
            
            displayFightLarge(fight);
            break;

        case '3':
            actionPlayer(fight, 3);
            fight->laps++;
            displayFightLarge(fight);
            break;

        case '4':
            actionPlayer(fight, 4);
            break;
        
        default:
            break;
        }
    }
    while (action != '2' || action != '3' ||action != '4');
    printf("\n\n");
}

/* Choix de l'arme pour le combat */
int chooseWeaponFight(Player *player){
    int nbWeapon = nbItemInInventory(player, 0);

    if(nbWeapon > 0){
        clear_screen();
        printf("CHOOSE YOUR WEAPON\n\n");

        displayWeaponInInventoryForFight(player,0);
        printf("\npress q to go back to the game...\n");

        printf("YOUR CHOICE : ");

        int weapon = 0;
        weapon = getchar();

        int noWeaponCoice = 0;
        //while (weapon > nbWeapon || weapon != 'q' || noWeaponCoice) { weapon = getchar(); }

        if(weapon == 'q'){
            return 0;
        } else {
            //placeItemInHand(player, weapon);
            return 1;
        }
    } else {
        printf("You do not have any weapon on your inventory %d\n",player->inventory.objects[0].property.type);
        return 0;
    }

}

/* Action du joueur en combat */
void actionPlayer(Fight *fight, int action) {
    switch (action)
    {
    case 2:
        attack(fight->player, fight->monster);
        fight->laps++;
        break;

    case 4:
        escapeFight(fight);
        break;

    default:
        break;
    }
}

/* Le joueur attaque avec inventory.objects[0] */
void attack(Player *player, Monster *monster) {
    printf("Atttack with : %s",player->hands.name);
    if(monster->health.HPcurrent - player->hands.property.damage <= 0){
        monster->health.HPcurrent = 0;
        killMonster(monster, player);
        return;
    } else {
        monster->health.HPcurrent -= player->hands.property.damage;
    }
}

/* void potion(Player player) {
    choice of potion
} */

void damage(Player *player, int damage) {
    if(player->health.HPcurrent - damage == 0){
        player->health.HPcurrent -= 1;
        int win = 1; //player lose, he is dead
        endFight(player, win);
    } else {
        player->health.HPcurrent -= damage;
    }
}

void escapeFight(Fight *fight) {
    time_t t;

    srand((unsigned) time(&t));
    int chance = rand() % 99;
    if (chance < 30) {
        fight->monster->respawn = 0;
        //endFight(fight->player,3);
    } else {
        printf("You try to escape, but you failed, you miss your turn...");
    }
}


/* Rendre un portail accessible */
void openPortail(Player *player) {
    //test niveau du joueur (lancé à chaque fin de combat) -> si possible débloque portail
}

/* Tuer le joueur */
void killPlayer(Player *player) {
    // kill level
    // kill health
    // kill inventory
    // free(player);
    //kill_game();
}