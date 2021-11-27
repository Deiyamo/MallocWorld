//
// Created by TimTim on 23/10/2021.
//

#include "player.h"
#include "monster.h"
#include "map.h"
#include "level.h"
#include "dialog.h"
#include "fight.h"
#include "events.h"
#include <stdio.h>

/*------------------------------------------------------
    Nicolas update
------------------------------------------------------*/

Fight newFight(Player *player ,Monster *monster) {
    Fight fight = {};

    fight.monster = monster;
    fight.player = player;
    fight.laps = 0;
    fight.end = 0;
    Point position;

    return fight;
}

void displayFightLarge(Fight *fight) {
    printf("Monster: %s VS Player : %s \n",
        fight->monster->name,
        fight->player->name
    );
    printf("\n");
    displayMonster(fight->monster);
    printf("\n\n");
    displayPlayerFight(fight);
    printf("\n\n");

    whoIsTurn(fight);
    //displayInteractionPlayer(fight);
}

void whoIsTurn(Fight *fight){
    if(fight->laps % 2 == 0){
        displayInteractionPlayer(fight);
    } else{
        displayActionMonster(fight);
    }
}

void startFight(Player *player, Monster *monster) {
    int weapon = chooseWeaponFight(player);
    /* if dont wna to fight exit else if displayFight */
    if(weapon){
        Fight fight = newFight(player, monster);
        displayFight(&fight);
    } else {
        restore_screen();
    }
}

void displayEndFight(Fight *fight, int win) {
    printf("The fight with a lose, LOSER\n");
    printf("\n\n");
    restore_screen();
}

void endFight(Fight *fight, int win) {
    switch (win)
    {
    case 1:
        /* win */
        increaseXpPlayer(fight->player, fight->monster->xpDrop);
        displayEndFight(fight, win);
        break;

    case 2:
        /* lose */
        displayEndFight(fight, win);
        killPlayer(fight->player);
    
    case 3:
        /* escape */
        restore_screen();
        //escapeFight(fight);
    
    default:
        break;
    }
}
