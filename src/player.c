//
// Created by TimTim on 23/10/2021.
//

#include "player.h"
#include "map.h"
#include "level.h"
#include "health.h"
#include "inventory.h"
#include "class.h"
#include "fight.h"
#include "monster.h"
#include "events.h"
#include "item.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define STARTING_XP 100


Player newPlayer(Game *game) {
    Player player;

    Item sword = {1, "Wooden sword", 1, 10, {Weapon, 10, 3, 1, 0 , 0}};

    player.name = "Sponge Bob";
    player.level = setLevelToZero();
    player.health = starting_health(100,100);
    player.inventory = starting_inventory();
    player.currentMap = 0;
    player.position = getPlayerPosition(game->map[0]);
    player.hands = sword;
    //printf("\n %d %d \n", player.position.X, player.position.Y);

    return player;
}


/*------------------------------------------------------
    HARVEST AND COLLECT
------------------------------------------------------*/

Game harvestPlant(Game* game, int casePosition, int x, int y) {
    // If player has a billhook in good shape
    int toolId = checkBillhookToUse(game->player.inventory, casePosition, casePosition);
    if ( toolId != 0 ) { // get the id of the billhook
        // Add items to inventory
        char **properties = getItemPropertiesFromFile(game->player.inventory, casePosition); // get item properties from Itemlist
        if (properties != NULL) { // if inventory not full
            *game = addItemHarvested(game, properties);
            for(int i = 0; i < 10; i++) {
                free(properties[i]);
            }
            free(properties);

            // Decrease the tool durability
            game->player.inventory = decreaseItemDurability(game->player.inventory, toolId, casePosition);
            // Move player
            updatePlayerPositionOnMap(game->player.position, x, y, game->map[game->player.currentMap]);
            game->player.position = updatePlayerPosition(game->player.position, x, y);
        }

        //displayDebugInventory(game->player.inventory);
        getchar();
    }

    return *game;
}

Game harvestRock(Game* game, int casePosition, int x, int y) {
    // If player has a pickaxe in good shape
    int toolId = checkPickaxeToUse(game->player.inventory, casePosition, casePosition);
    if ( toolId != 0 ) { // get the id of the pickaxe
        // Add items to inventory
        char **properties = getItemPropertiesFromFile(game->player.inventory, casePosition); // get item properties from Itemlist
        if (properties != NULL) { // if inventory not full
            *game = addItemHarvested(game, properties);
            for(int i = 0; i < 10; i++) {
                free(properties[i]);
            }
            free(properties);

            // Decrease the tool durability
            game->player.inventory = decreaseItemDurability(game->player.inventory, toolId, casePosition);
            // Move player
            updatePlayerPositionOnMap(game->player.position, x, y, game->map[game->player.currentMap]);
            game->player.position = updatePlayerPosition(game->player.position, x, y);
        }


        getchar();
        // careful to random !! It's not a real random !! TO FIX
        // stack item when not 20 yet
        return *game;
    }

    return *game;
}

Game harvestTree(Game* game, int casePosition, int x, int y) {
    // If player has an axe in good shape
    int toolId = checkAxeToUse(game->player.inventory, casePosition, casePosition);
    if ( toolId != 0 ) { // get the id of the axe
        // Add items to inventory
        char **properties = getItemPropertiesFromFile(game->player.inventory, casePosition); // get item properties from Itemlist
        if (properties != NULL) { // if inventory not full
            *game = addItemHarvested(game, properties);
            for(int i = 0; i < 10; i++) {
                free(properties[i]);
            }
            free(properties);

            // Decrease the tool durability
            game->player.inventory = decreaseItemDurability(game->player.inventory, toolId, casePosition);
            // Move player
            updatePlayerPositionOnMap(game->player.position, x, y, game->map[game->player.currentMap]);
            game->player.position = updatePlayerPosition(game->player.position, x, y);
        }

        getchar();
    }

    return *game;
}


/*------------------------------------------------------
    Nicolas update
------------------------------------------------------*/

/* Affichage du joueur */
void displayPlayer(Player *player) {
    printf("\nPlayer : %s\n", player->name);
    printf("Lvl : %d\n", player->level.floor);
    printf("%d / %d XP\n", player->level.XpCurrent, player->level.XpMax);
    printf("%d / %d HP\n", player->health.currentHp, player->health.maxHp);
    printf("Inventaire cap. : %d\n", player->inventory.maxCapacity);

    displayInventoryFromMaxCapacity(player->inventory);
    displayPlayerPosition(player->position);
}

/* Affichage du joueur pendant le combat */
void displayPlayerFight(Fight *fight) {
    printf("\nPlayer : %s\n", fight->player->name);
    printf("Lvl : %d\n", fight->player->level.floor);
    printf("%d / %d HP\n", fight->player->health.currentHp, fight->player->health.maxHp);
    printf("%d / %d XP\n", fight->player->level.XpCurrent, fight->player->level.XpMax);
}

/* Affichage de la postion du joueur */
void displayPlayerPosition(Point position) {
    printf("\n Tu es en position : {%d, %d}\n", position.X, position.Y);
}


/* Affichage des actions possibles du joueur pendant un combat */

void displayInteractionPlayer(Game *game, Fight *fight) {
    printf("\n\n");
    printf("Player action: \n 2. Attack \n 3. Potion \n 4. Escape \n\n");
    printf("Press the action you want to do : ");

    char action;
    do{
        scanf("%c",&action);
        getchar();
        action -= 48;
    }
    while (action != 2 && action != 3 && action != 4);

    switch (action)
    {
        case 2:
            actionPlayer(game, fight, 2);
            displayFightLarge(game, fight);
            break;

        case 3:
            actionPlayer(game, fight, 3);
            break;

        case 4:
            actionPlayer(game, fight, 4);
            displayFightLarge(game, fight);
            break;

        default:
            break;
    }
}

/*  */
void healthPlayer(Player *player, int heal){
    if (player->health.currentHp == player->health.maxHp) {
        printf("You already have full health\n");
    } else {
        if((player->health.currentHp + heal) >= player->health.maxHp) {
            player->health.currentHp = player->health.maxHp;
        } else {
            player->health.currentHp += heal;
        }
    }
}

/* Affichage du menu de choix de potion */
void displayChoosePotion(Player *player){
    clear_screen();
    printf("CHOOSE YOUR POTION\n\n");

    displayItemInInventoryForFight(player,Heal);
    printf("\npress q to go back to the fight...\n\n");

    printf("YOUR CHOICE : ");
}

/* Choix de la potion à utiliser */
int choosePotionFight(Player *player){
    int nbPotion = nbItemInInventory(player, 4);

    if(nbPotion > 0){
        char potion;
        do {
            displayChoosePotion(player);
            scanf("%c",&potion);
            getchar();
        }while (isItemOfType(player->inventory.item[potion-48],Heal) != 1 && potion != 'q');

        if(potion == 'q'){
            return 0;
        } else {
            healthPlayer(player,player->inventory.item[potion-48].property.heal);
            //player->inventory.item[potion-48].quantity -= 1;
            memset(&player->inventory.item[potion-48], 0, sizeof(Item));
            player->inventory.currentCapacity -= 1;
            return 1;
        }
    } else {
        printf("You do not have any potion on your inventory\n");
        return 0;
    }
}

/* Affichage du menu de choix de l'arme */
void displayChooseWeapon(Player *player){
    clear_screen();
    printf("CHOOSE YOUR WEAPON\n\n");

    displayItemInInventoryForFight(player,Weapon);
    printf("\npress q to go back to the game...\n\n");
    printf("YOUR CHOICE : ");
}

/* Choix de l'arme pour le combat */
int chooseWeaponFight(Player *player) {
    int nbWeapon = nbItemInInventory(player, 0);

    if (nbWeapon > 0) {
        char weapon;
        do {
            displayChooseWeapon(player);
            scanf("%c", &weapon);
            getchar();
        } while (isItemOfType(player->inventory.item[weapon - 48], Weapon) != 1 && weapon != 'q');

        if (weapon == 'q') {
            return 0;
        } else {
            placeItemInHand(player, weapon - 48);
            return 1;
        }
    } else {
        printf("You do not have any weapon on your inventory\n");
        return 0;
    }
}

/* Action du joueur en combat */
void actionPlayer(Game* game, Fight *fight, int action) {
    int choosePotion;
    switch (action)
    {
    case 2:
        attack(fight);
        break;
    case 3:
        choosePotion = choosePotionFight(fight->player);
        if(choosePotion == 1){
            fight->laps++;
            displayFightLarge(game, fight);
        } else {
            displayFightLarge(game, fight);
        }
        break;
    case 4:
        escapeFight(fight);
        break;

    default:
        break;
    }
}

/* Le joueur attaque avec inventory.item[0] */
void attack(Fight *fight) {
    printf("Atttack with : %s\n",fight->player->hands.name);
    if(fight->monster->health.currentHp - fight->player->hands.property.damage <= 0){
        killMonster(fight);
    } else {
        fight->monster->health.currentHp -= fight->player->hands.property.damage;
        fight->laps++;
    }
    fight->player->hands.durability -= 1;
}

/* Degat subit par le joueur */
void damagePlayer(Fight *fight, int damage) {
    if(fight->player->health.currentHp - damage <= 0){
        fight->player->health.currentHp = 0;
        fight->status = 2;
    } else {
        if(nbItemInInventory(fight->player, 3)){
            int idArmor = findArmor(fight->player);
            int resistanceDamage = ((damage * fight->player->inventory.item[idArmor].property.resistance) / 100);
            fight->player->health.currentHp = damage - resistanceDamage;
        } else {
            fight->player->health.currentHp -= damage;
            fight->laps++;
        }
    }
}

/* Tentative de fuite du combat par le joueur */
void escapeFight(Fight *fight) {
    time_t t;

    srand((unsigned) time(&t));
    int chance = rand() % 99;
    if (chance < 30) {
        fight->monster->respawn = 0;
        fight->status = 3;
    } else {
        fight->status = 0;
        fight->laps ++;
        printf("You try to escape, but you failed, you miss your turn...\n");
    }
}

/* Tuer le joueur */
void killPlayer(Player *player) {
    // kill level
    // kill health
    // kill inventory
    // free(player);
    //kill_game();
    //runMain();
}