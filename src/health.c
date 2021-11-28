//
// Created by TimTim on 24/10/2021.
//

#include "health.h"

#define STARTING_HP 10

Health starting_health(int currentHealth, int maxHealth) {

    Health health;

    health.currentHp = currentHealth;
    health.maxHp = maxHealth;

    set_health_to_max(&health);

    return health;
}

void set_health_to_max(Health *health) {
    health->currentHp = health->maxHp;
}