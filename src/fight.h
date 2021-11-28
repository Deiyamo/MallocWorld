//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_FIGHT_H
#define MALLOC_WORLD_FIGHT_H

#include "types.h"

Fight newFight(Player* player, Monster* monster);
void displayFightLarge(Game* game, Fight* fight);
void whoIsTurn(Game* game, Fight* fight);
void startFight(Game* game, int idMonster);
void endFight(Game* game, Fight *fight, int status);


#endif //MALLOC_WORLD_FIGHT_H
