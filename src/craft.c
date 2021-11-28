//
// Created by TimTim on 27/11/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "craft.h"
#include "inventory.h"

int checkItemRequired(Inventory inventory, int itemId) {
    switch (itemId+1) {
        case 1:
            return ifCraftIs1(inventory);
        case 2:
            return ifCraftIs2(inventory);
        case 3:
            return ifCraftIs3(inventory);
        case 4:
            return ifCraftIs4(inventory);
        case 5:
            return ifCraftIs5(inventory);
        case 6:
            return ifCraftIs6(inventory);
        case 7:
            return ifCraftIs7(inventory);
        case 8:
            return ifCraftIs8(inventory);
        case 9:
            return ifCraftIs9(inventory);
        case 10:
            return ifCraftIs10(inventory);
        case 11:
            return ifCraftIs11(inventory);
        case 12:
            return ifCraftIs12(inventory);
        case 13:
            return ifCraftIs13(inventory);
        case 14:
            return ifCraftIs14(inventory);
        case 15:
            return ifCraftIs15(inventory);
        case 16:
            return ifCraftIs16(inventory);
        case 17:
            return ifCraftIs17(inventory);
        case 18:
            return ifCraftIs18(inventory);
        case 19:
            return ifCraftIs19(inventory);
        case 20:
            return ifCraftIs20(inventory);
        case 21:
            return ifCraftIs21(inventory);
        case 22:
            return ifCraftIs22(inventory);
        case 23:
            return ifCraftIs23(inventory);
        case 24:
            return ifCraftIs24(inventory);
        case 25:
            return ifCraftIs25(inventory);
        default:
            return 0;
    }

}

int checkZoneRequired(int currentMap, int itemId) {
    switch (itemId+1) {
        case 1:
        case 2:
        case 5:
        case 8:
        case 11:
        case 14:
        case 15:
        case 17:
        case 18:
        case 20:
        case 21:
        case 23:
            return ifCraftAllowThreeZone(currentMap);
        case 3:
        case 6:
        case 9:
        case 12:
        case 16:
        case 19:
        case 22:
        case 24:
            return ifCraftAllowTwoZone(currentMap);
        case 4:
        case 7:
        case 10:
        case 13:
        case 25:
            return ifCraftAllowOneZone(currentMap);
        default:
            return 0;
    }
}


char** getCraftItemProperties(int itemId) {
    FILE *fp;
    const char* separators = "{}"; // separators list
    fp = fopen("../resources/craftList", "r");

    char line[90]; // maximum line size !
    int lineNumber = 1;

    if (fp != NULL) {
        char** properties = malloc(sizeof(char*) * 10);
        fgets(line, sizeof line, fp);
        fgets(line, sizeof line, fp);
        fgets(line, sizeof line, fp);
        while (fgets(line, sizeof line, fp) != NULL) {
            if (lineNumber == itemId+1) {
                char* strToken = strtok(line, separators);

                for (int j = 0 ; strToken != NULL ; j++) {
                    properties[j] = malloc(sizeof(char) * 20);
                    strcpy(properties[j], strToken);

                    strToken = strtok(NULL, separators);
                }
            }
            lineNumber++;
        }
        fclose(fp);
        return properties;
    } else {
        printf("/!\\ Error while opening craftList file...");
    }

    return NULL;
}

/*int checkItemsInInventory(Inventory inventory, char** name, const int* quantity, int size) {
    if (size != 0) {
        for (int i = 0; i < inventory.maxCapacity; i++) {
            for (int j = 0; j < size; j++) {
                if (inventory.item[i].name == name[j] && inventory.item[i].quantity >= quantity[j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}*/

// Zone 1, 2, & 3
int ifCraftAllowThreeZone(int currentMap) {
    if (currentMap == 0 || currentMap == 1 || currentMap == 2) {
        return 1;
    }
    return 0;
}
// Zone 2 & 3
int ifCraftAllowTwoZone(int currentMap) {
    if (currentMap == 1 || currentMap == 2) {
        return 1;
    }
    return 0;
}
// Zone 3
int ifCraftAllowOneZone(int currentMap) {
    if (currentMap == 2) {
        return 1;
    }
    return 0;
}

int ifCraftIs1(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 3) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs2(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Stone") == 0 && inventory.item[i].quantity >= 3) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs3(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Beech") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Iron") == 0 && inventory.item[i].quantity >= 4) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs4(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Oak") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Diamond") == 0 && inventory.item[i].quantity >= 5) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs5(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 3
                && strcmp(inventory.item[i].name, "Stone") == 0 && inventory.item[i].quantity >= 4) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs6(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Beech") == 0 && inventory.item[i].quantity >= 3
                && strcmp(inventory.item[i].name, "Iron") == 0 && inventory.item[i].quantity >= 5) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs7(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Oak") == 0 && inventory.item[i].quantity >= 3
                && strcmp(inventory.item[i].name, "Diamond") == 0 && inventory.item[i].quantity >= 6) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs8(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Stone") == 0 && inventory.item[i].quantity >= 6) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs9(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Beech") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Iron") == 0 && inventory.item[i].quantity >= 7) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs10(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Oak") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Diamond") == 0 && inventory.item[i].quantity >= 8) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs11(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Stone") == 0 && inventory.item[i].quantity >= 10) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs12(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Iron") == 0 && inventory.item[i].quantity >= 12) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs13(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Diamond") == 0 && inventory.item[i].quantity >= 16) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs14(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 3) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs15(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Stone") == 0 && inventory.item[i].quantity >= 3) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs16(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Beech") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Iron") == 0 && inventory.item[i].quantity >= 4) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs17(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 3) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs18(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Stone") == 0 && inventory.item[i].quantity >= 3) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs19(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Beech") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Iron") == 0 && inventory.item[i].quantity >= 4) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs20(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 3) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs21(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Fir") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Stone") == 0 && inventory.item[i].quantity >= 3) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs22(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Beech") == 0 && inventory.item[i].quantity >= 2
                && strcmp(inventory.item[i].name, "Iron") == 0 && inventory.item[i].quantity >= 4) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs23(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Grass") == 0 && inventory.item[i].quantity >= 2) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs24(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Lavender") == 0 && inventory.item[i].quantity >= 2) {
                return 1;
            }
        }

    }
    return 0;
}
int ifCraftIs25(Inventory inventory) {
    for (int i = 0; i < inventory.maxCapacity; i++) {
        if (inventory.item[i].id != 0) {
            if (strcmp(inventory.item[i].name, "Hemp") == 0 && inventory.item[i].quantity >= 2) {
                return 1;
            }
        }

    }
    return 0;
}

Game subtractItemRequired(Game* game, int itemId) {
    switch (itemId+1) {
        case 1:
            return craft1(game);
        case 2:
            return craft2(game);
        case 3:
            return craft3(game);
        case 4:
            return craft4(game);
        case 5:
            return craft5(game);
        case 6:
            return craft6(game);
        case 7:
            return craft7(game);
        case 8:
            return craft8(game);
        case 9:
            return craft9(game);
        case 10:
            return craft10(game);
        case 11:
            return craft11(game);
        case 12:
            return craft12(game);
        case 13:
            return craft13(game);
        case 14:
            return craft14(game);
        case 15:
            return craft15(game);
        case 16:
            return craft16(game);
        case 17:
            return craft17(game);
        case 18:
            return craft18(game);
        case 19:
            return craft19(game);
        case 20:
            return craft20(game);
        case 21:
            return craft21(game);
        case 22:
            return craft22(game);
        case 23:
            return craft23(game);
        case 24:
            return craft24(game);
        case 25:
            return craft25(game);
        default:
            return *game;
    }

}

Game craft1(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 3);
            return *game;
        }

    }
    return *game;
}
Game craft2(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 2);
            *game = subtractItemFromInventory(game, "Stone", 3);
            return *game;
        }

    }
    return *game;
}
Game craft3(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Beech", 2);
            *game = subtractItemFromInventory(game, "Iron", 4);
            return *game;
        }

    }
    return *game;
}
Game craft4(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Oak", 2);
            *game = subtractItemFromInventory(game, "Diamond", 5);
            return *game;
        }

    }
    return *game;
}
Game craft5(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 3);
            *game = subtractItemFromInventory(game, "Stone", 4);
            return *game;
        }

    }
    return *game;
}
Game craft6(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Beech", 3);
            *game = subtractItemFromInventory(game, "Iron", 5);
            return *game;
        }

    }
    return *game;
}
Game craft7(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Oak", 3);
            *game = subtractItemFromInventory(game, "Diamond", 6);
            return *game;
        }

    }
    return *game;
}
Game craft8(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 2);
            *game = subtractItemFromInventory(game, "Stone", 6);
            return *game;
        }

    }
    return *game;
}
Game craft9(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Beech", 2);
            *game = subtractItemFromInventory(game, "Iron", 7);
            return *game;
        }

    }
    return *game;
}
Game craft10(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Oak", 2);
            *game = subtractItemFromInventory(game, "Diamond", 8);
            return *game;
        }

    }
    return *game;
}
Game craft11(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Stone", 10);
            return *game;
        }

    }
    return *game;
}
Game craft12(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Iron", 12);
            return *game;
        }

    }
    return *game;
}
Game craft13(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Diamond", 16);
            return *game;
        }

    }
    return *game;
}
Game craft14(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 3);
            return *game;
        }

    }
    return *game;
}
Game craft15(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 2);
            *game = subtractItemFromInventory(game, "Stone", 3);
            return *game;
        }

    }
    return *game;
}
Game craft16(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Beech", 2);
            *game = subtractItemFromInventory(game, "Iron", 4);
            return *game;
        }

    }
    return *game;
}
Game craft17(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 3);
            return *game;
        }

    }
    return *game;
}
Game craft18(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 2);
            *game = subtractItemFromInventory(game, "Stone", 3);
            return *game;
        }

    }
    return *game;
}
Game craft19(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Beech", 2);
            *game = subtractItemFromInventory(game, "Iron", 4);
            return *game;
        }

    }
    return *game;
}
Game craft20(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 3);
            return *game;
        }

    }
    return *game;
}
Game craft21(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Fir", 2);
            *game = subtractItemFromInventory(game, "Stone", 3);
            return *game;
        }

    }
    return *game;
}
Game craft22(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Beech", 2);
            *game = subtractItemFromInventory(game, "Iron", 4);
            return *game;
        }

    }
    return *game;
}
Game craft23(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Grass", 2);
            return *game;
        }

    }
    return *game;
}
Game craft24(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Lavender", 2);
            return *game;
        }

    }
    return *game;
}
Game craft25(Game* game) {
    for (int i = 0; i < game->player.inventory.maxCapacity; i++) {
        if (game->player.inventory.item[i].id != 0) {
            *game = subtractItemFromInventory(game, "Hemp", 2);
            return *game;
        }

    }
    return *game;
}