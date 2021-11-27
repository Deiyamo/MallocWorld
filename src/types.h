//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_TYPES_H
#define MALLOC_WORLD_TYPES_H

#include <time.h>


typedef struct Point {
    int X;
    int Y;
} Point;

typedef struct Level {
    int floor; // player's level
    int maxFloor; // player's level
    int XpCurrent; // Current player's XP
    int XpMax; // Max level's XP before the next one
} Level;

typedef struct Health {
    int currentHp; // Current player's HP
    int maxHp; // Max player's HP
} Health;

typedef enum Class {
    Weapon, // 0
    Tool, // 1
    Craft, // 2
    Armor, // 3
    Heal // 4
} Class;

typedef struct Property {
    Class type; // Item type's name
    int durability_max; // Durability before it breaks
    int damage; // Number that define how much damage it deals
    int stack; // Number of the same element can be stocked in one slot
    int heal; // Number of health point it procures
    int resistance; // Armor percentage
} Property;

typedef struct Item {
    int id; // Item's ID
    char* name; // Item's name
    int quantity; // Item's quantity
    int durability; // Item's durability
    Property property; // Item's type
    //Item* schema; // Craft Schema
} Item;

typedef struct Inventory {
    int maxCapacity; // max capacity of the inventory
    int currentCapacity; // current capacity of the inventory
    Item* objects; //
} Inventory;



typedef struct Player {
    char* name; // player's name
    Level level; // player's experience
    int maxXp; // player's max xp
    Health health; // player's health
    Inventory inventory; // player's inventory
    Point position; // player's position
    Item hands; // item grab in them hands
} Player;

typedef struct Monster {
    int id; // monster's ID
    char* name; // monster's name
    Health health; // monster's health
    int damage; // Number that define how much damage it deals
    int xpDrop; // Number that define how much experience it drop when kill
    int respawn; // Number that define how many turn is left before he can reaper
    Point position; // monster's position
} Monster;

typedef struct Fight {
    Monster *monster; // monster's ID
    Player *player; // player's ID
    int laps; // nb laps
    int end; // the fight is over ?
    Point position; // fight's position (monster's position)
} Fight;






typedef struct Npc {
    char* name; // npc's name
    Inventory storage;
} Npc;

typedef struct Game {
    //Map map; // ???? a voir avec Eduard ????
    // currentMap
    Player player; // the player
    Npc npc; // the player's storage
    //time_t started; // timestamp when the game has been started
    //time_t ended;  // timestamp when the has been ended
    //time_t paused; // the amount of seconds the game was paused
} Game;


#endif //MALLOC_WORLD_TYPES_H
