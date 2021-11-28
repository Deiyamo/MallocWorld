//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_PLAYER_H
#define MALLOC_WORLD_PLAYER_H

#include "types.h"


Player newPlayer(Game *game);


void display_player(Player player);
void displayPlayerPosition(Point position);

Game harvestPlant(Game* game, int casePosition, int x, int y);
Game harvestRock(Game* game, int casePosition, int x, int y);
Game harvestTree(Game* game, int casePosition, int x, int y);


void kill_player();

int chooseWeaponFight(Player* player);
void attack(Fight* fight);
void damagePlayer(Fight* fight, int damage);
void escapeFight(Fight* fight);
void actionPlayer(Game* game, Fight *fight, int action);
void killPlayer(Player* player);

void healthPlayer(Player* player, int heal);
void displayChoosePotion(Player* player);
int choosePotionFight(Player* player);

void displayChooseWeapon(Player* player);
void displayPlayer(Player* player);
void displayPlayerFight(Fight* fight);
void displayInteractionPlayer(Game* game, Fight *fight);



#endif //MALLOC_WORLD_PLAYER_H
