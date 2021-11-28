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
#include <stdlib.h>

Monster createMonster(int idMonster) {
    char* monsters[88][6] = {
        /* Name - hp - hpMax - damage - xpDrop - respawn */
        {"Evil","1","1","6","1","15"},
        {"Jesus","1","1","7","1","15"},
        {"Dark Vador","3","3","12","3","15"},
        {"Dracula","4","4","12","4","15"},
        {"Godzila","5","5","12","5","15"},
        {"King Kong","5","5","12","8","15"},
        {"Bowser","12","12","12","3","15"},
        {"The Boss","5","5","9","12","15"},
        {"Joker","7","7","12","14","15"},
        {"Sauron","20","20","12","0","15"},
        {"Voldemor","21","21","12","17","15"},
        {"Solid Snake","20","20","12","100","15"},
        {"Rambo","20","20","12","100","15"},
        {"Kratos","20","20","12","100","15"},
        {"Hades","20","20","12","100","15"},
        {"Zeus","20","20","12","100","15"},
        {"Bane","33","33","12","100","15"},
        {"Frankenstein","37","37","12","100","15"},
        {"Jigsaw","20","20","12","100","15"},
        {"Terminator","20","20","12","100","15"},
        {"Jack Torrance","20","20","12","100","15"},
        {"Hannibal Lecter","20","20","12","100","15"},
        {"Ghostface","20","20","12","100","15"},
        {"Vaas","20","20","12","100","15"},
        {"Ganondorf","20","20","12","100","15"},
        {"Dr Robotnik","20","20","12","100","15"},
        {"Sephiroth","20","20","12","100","15"},
        {"Nemesis","20","20","12","100","15"},
        {"Dr Wily","20","20","12","100","15"},
        {"M.Bison","20","20","12","100","15"},
        {"Pyscho Mantis","20","20","12","100","15"},
        {"Freezer","20","20","12","100","15"},
        {"Eren Jaeger","20","20","12","100","15"},
        {"All for one","20","20","12","100","15"},
        {"Overhaul","20","20","12","100","15"},
        {"Stain","20","20","12","100","15"},
        {"Dabi","67","67","12","100","15"},
        {"Pain","20","20","12","100","15"},
        {"L","20","20","12","100","15"},
        {"Snake","20","20","12","100","15"},
        {"Witch","20","20","12","100","15"},
        {"Snake","20","20","12","100","15"},
        {"Witch","20","20","12","100","15"},
        {"Snake","20","20","12","100","15"},
        {"Witch","20","20","12","100","15"},
        {"Snake","20","20","12","100","15"},
        {"Witch","20","20","12","100","15"},
        {"Snake","20","20","12","100","15"},
        {"Witch","20","20","12","100","15"},
        {"Snake","20","20","12","100","15"},
        {"Witch","20","20","12","38","15"},
        {"Snake","20","20","12","38","15"},
        {"Witch","20","20","12","30","15"},
        {"Snake","20","20","12","40","15"},
        {"Witch","20","20","12","40","15"},
        {"Snake","80","80","12","88","15"},
        {"Witch","20","20","12","100","15"},
        {"Snake","20","20","12","100","15"},
        {"Witch","20","20","12","56","15"},
        {"Yellow Snake","20","20","12","47","15"},
        {"Yellow Witch","20","20","12","48","15"},
        {"Red Snake","20","20","12","55","15"},
        {"Red Witch","20","20","12","100","15"},
        {"Blue Snake","20","20","12","100","15"},
        {"Blue Witch","20","20","12","100","15"},
        {"Dark Snake","20","20","12","100","15"},
        {"Dark Witch","20","20","12","100","15"},
        {"Grey Snake","20","20","12","100","15"},
        {"Grey Witch","20","20","12","100","15"},
        {"Cat","20","20","12","100","15"},
        {"Witch","20","20","12","100","15"},
        {"Shark","20","20","12","100","15"},
        {"Spider","20","20","12","100","15"},
        {"Jack","20","20","12","100","15"},
        {"Skeleton","20","20","12","100","15"},
        {"Raw","20","20","12","38","15"},
        {"Wolf","20","20","12","100","15"},
        {"Rat","20","20","12","56","15"},
        {"Bat","20","20","12","63","15"},
        {"Snake","20","20","12","88","15"},
        {"Cow","20","20","12","60","15"},
        {"Snake","20","20","12","68","15"},
        {"Wizard","74","74","12","75","15"},
        {"Gnome","77","77","12","64","15"},
        {"Witch","120","120","50","65","15"},
        {"Snake","99","99","69","88","15"},
        {"Snake","100","100","44","99","15"},
        {"White Sheep","222","222","120","666666","15"},
    };

    Monster monster;

    int realIdMonster = idMonster-12;
    monster.id = realIdMonster;
    monster.name = monsters[realIdMonster][0];
    monster.health = starting_health(atoi(monsters[realIdMonster][1]),atoi(monsters[realIdMonster][2]));
    monster.damage = atoi(monsters[realIdMonster][3]);
    monster.xpDrop = atoi(monsters[realIdMonster][4]);
    monster.respawn = atoi(monsters[realIdMonster][5]);

    return monster;
}


void displayMonster(Monster *monster) {
    //use in display_fight
    printf("Monster : %s\n", monster->name);
    printf("%d / %d HP\n", monster->health.currentHp, monster->health.maxHp);
}

void displayActionMonster(Game* game, Fight *fight) {
    printf("\n\n");
    printf("Monster attack: %d dmg\n" , fight->monster->damage);
    attackMonster(game, fight);
    printf("\n\n");
}

/* Le monstre attaque le joueur */
void attackMonster(Game* game, Fight *fight) {
    damagePlayer(fight,fight->monster->damage);
    displayFightLarge(game, fight);
}

/* Xp drop par le monstre lorsqu'il est tué */
void dropXpMonster(Monster *monster, Player *player) {
    increaseXpPlayer(player,monster->xpDrop);
}

/* Tue le monstre -> défini son status à mort et met son nombre de tour avant de respawn à 15 */
void killMonster(Fight *fight){
    fight->monster->health.currentHp = 0;
    dropXpMonster(fight->monster, fight->player);
    fight->status = 1;
}
