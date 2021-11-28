//
// Created by TimTim on 28/11/2021.
//

#ifndef MALLOC_WORLD_CRAFT_H
#define MALLOC_WORLD_CRAFT_H

#include "types.h"

int checkItemRequired(Inventory inventory, int itemId);
int checkZoneRequired(int currentMap, int itemId);
int checkItemsInInventory(Inventory inventory, char** name, const int* quantity, int size);

char** getCraftItemProperties(int itemId);

int ifCraftAllowThreeZone(int currentMap);
int ifCraftAllowTwoZone(int currentMap);
int ifCraftAllowOneZone(int currentMap);


int ifCraftIs1(Inventory inventory);
int ifCraftIs2(Inventory inventory);
int ifCraftIs3(Inventory inventory);
int ifCraftIs4(Inventory inventory);
int ifCraftIs5(Inventory inventory);
int ifCraftIs6(Inventory inventory);
int ifCraftIs7(Inventory inventory);
int ifCraftIs8(Inventory inventory);
int ifCraftIs9(Inventory inventory);
int ifCraftIs10(Inventory inventory);
int ifCraftIs11(Inventory inventory);
int ifCraftIs12(Inventory inventory);
int ifCraftIs13(Inventory inventory);
int ifCraftIs14(Inventory inventory);
int ifCraftIs15(Inventory inventory);
int ifCraftIs16(Inventory inventory);
int ifCraftIs17(Inventory inventory);
int ifCraftIs18(Inventory inventory);
int ifCraftIs19(Inventory inventory);
int ifCraftIs20(Inventory inventory);
int ifCraftIs21(Inventory inventory);
int ifCraftIs22(Inventory inventory);
int ifCraftIs23(Inventory inventory);
int ifCraftIs24(Inventory inventory);
int ifCraftIs25(Inventory inventory);


Game subtractItemRequired(Game* game, int itemId);

Game craft1(Game* game);
Game craft2(Game* game);
Game craft3(Game* game);
Game craft4(Game* game);
Game craft5(Game* game);
Game craft6(Game* game);
Game craft7(Game* game);
Game craft8(Game* game);
Game craft9(Game* game);
Game craft10(Game* game);
Game craft11(Game* game);
Game craft12(Game* game);
Game craft13(Game* game);
Game craft14(Game* game);
Game craft15(Game* game);
Game craft16(Game* game);
Game craft17(Game* game);
Game craft18(Game* game);
Game craft19(Game* game);
Game craft20(Game* game);
Game craft21(Game* game);
Game craft22(Game* game);
Game craft23(Game* game);
Game craft24(Game* game);
Game craft25(Game* game);

#endif //MALLOC_WORLD_CRAFT_H
