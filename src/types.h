//
// Created by TimTim on 23/10/2021.
//

#ifndef MALLOC_WORLD_TYPES_H
#define MALLOC_WORLD_TYPES_H

#include <time.h>


typedef struct Level {
    int floor; // player's level
    int XPcurrent; // Current player's XP
    int XPmax; // Max level's XP before the next one
} Level;

typedef struct Health {
    int HPcurrent; // Current player's HP
    int HPmax; // Max player's HP
} Health;

typedef enum Type {
    Weapon, // 0
    Tool, // 1
    Craft, // 2
    Armor, // 3
    Heal // 4
} Type;

typedef struct Property {
    Type type; // Object type's name
    int durability_max; // Durability before it breaks
    int damage; // Number that define how much damage it deals
    int stack; // Number of the same element can be stocked in one slot
    int heal; // Number of health point it procures
    int resistance; // Armor percentage
} Property;

typedef struct Object {
    int id; // Object's ID
    char* name; // Object's name
    int quantity; // Object's quantity
    int durability; // Object's durability
    Property property; // Object's type
} Object;

typedef struct Inventory {
    int maxCapacity; // max capacity of the inventory
    Object* objects; // even possible ???
} Inventory;


typedef struct Player {
    char* name; // player's name
    Level level; // player's experience
    Health health; // player's health
    Inventory inventory; // player's inventory
} Player;

typedef struct Game {
    //Map map; // ???? a voir avec Eduard ????
    Player player; // the player
    //time_t started; // timestamp when the game has been started
    //time_t ended;  // timestamp when the has been ended
    //time_t paused; // the amount of seconds the game was paused
} GAME;


#endif //MALLOC_WORLD_TYPES_H
