//
// Created by Nico on 01/11/2021.
//

#include "monster.h"
#include "map.h"
#include "health.h"
#include "player.h"
#include "fight.h"
#include "level.h"

#include <stdio.h>

Monster createMonster() {
    Monster monster = {};

    monster.id = 13;
    monster.name = "Dark Vador";
    monster.health = starting_health(66,66);
    monster.damage = 7;
    monster.xpDrop = 32;
    monster.respawn = 0;
    Point position; // monster's position

    return monster;
}


void displayMonster(Monster *monster) {
    //use in display_fight
    printf("Monster : %s\n", monster->name);
    printf("%d / %d HP\n", monster->health.HPcurrent, monster->health.HPmax);
}

void displayActionMonster(Fight *fight) {
    printf("\n\n");
    printf("Monster attack: %d dmg\n" , fight->monster->damage);
    attackMonster(fight);
    printf("\n\n");
}

void attackMonster(Fight *fight) {
    /*monster attack player (lose hp), une vérification doit être faite après l'appel de cette fonction
    pour voir si player dead
    */
    damage(fight->player,fight->monster->damage);
    fight->laps++;
    displayFightLarge(fight);
}

void dropXpMonster(Monster *monster, Player *player) {
    //use when killMonster() -> give xp from monster to player when p kill m
    //call end -> XPincrease_player()
    increaseXpPlayer(player,monster->xpDrop);
}

void killMonster(Monster *monster, Player *player){
    //call end -> dropXpMonster()
    //set the timer of respawn on 0
    //monster->respawn = 0;
    dropXpMonster(monster, player);
}

//pour le respawn doit être gérer ailleur car je garde pas la struct du monster
void respawnMonster(Monster monster) {
    /*use the monster postion to place it, accéder au tableau asso et récupérer pour le mmonstre précis
    ses coordonnées et mettre  sont tour de respawn à 15
    */
}