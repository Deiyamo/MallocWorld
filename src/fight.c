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
    fight.status = 0;
    Point position;

    return fight;
}

void displayFightLarge(Fight *fight) {
    if(fight->status == 0){
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
    } else {
        endFight(fight,fight->status);
    }
}

void whoIsTurn(Fight *fight){
    if(fight->laps % 2 == 0){
        displayInteractionPlayer(fight);
    } else{
        displayActionMonster(fight);
    }
}

void startFight(Player *player, int idMonster) {
    int weapon = chooseWeaponFight(player);
    if(weapon){
        Monster monster = createMonster(idMonster);
        Fight fight = newFight(player,&monster);
        displayFight(&fight);
    } else {
        restore_screen();
    }
}

void endFight(Fight *fight, int status) {
    switch (status)
    {
    case 1:
        /* win */
        printf("You win the fight\n");
        printf("\n\n");
        clear_screen();
        /* restore_screen(); */
        break;

    case 2:
        /* lose */
        printf("Your die\n");
        printf("\n\n");
        killPlayer(fight->player);
        //restore_screen();
    
    case 3:
        /* escape */
        printf("You escape the fight, good job...\n");
        restore_screen();
        //escapeFight(fight);
    
    default:
        break;
    }
}
