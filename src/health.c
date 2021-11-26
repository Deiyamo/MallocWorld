//
// Created by TimTim on 24/10/2021.
//

#include "health.h"

#define STARTING_HP 10

Health starting_health() {

    Health health;

    health.HPcurrent = 0;
    health.HPmax = STARTING_HP;

    set_health_to_max(health);

    return health;
}

Health set_health_to_max(Health health) {

    health.HPcurrent = health.HPmax;

    return health;
}