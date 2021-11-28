//
// Created by TimTim on 24/10/2021.
//

#ifndef MALLOC_WORLD_HEALTH_H
#define MALLOC_WORLD_HEALTH_H

#include "types.h"

Health starting_health();
void set_health_to_max(Health *health);
Health upgrade_health_max();
Health enhance_health(Health health, int amount);

#endif //MALLOC_WORLD_HEALTH_H
