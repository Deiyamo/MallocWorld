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
    int XPcurrent; // Current player's XP
    int XPmax; // Max level's XP before the next one
} Level;

typedef struct Health {
    int HPcurrent; // Current player's HP
    int HPmax; // Max player's HP
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
    Item* item; //
} Inventory;


typedef struct Player {
    char* name; // player's name
    Level level; // player's experience
    Health health; // player's health
    Inventory inventory; // player's inventory
    Point position; // player's position
} Player;

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
    //char* saveFile; // Save file that contains : map, inventory, storage, player's stats, etc...
} Game;


#endif //MALLOC_WORLD_TYPES_H
