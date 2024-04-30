//
// Created by masafumi on 4/30/24.
//

#ifndef ROBOMASTER_C610_DEF_H
#define ROBOMASTER_C610_DEF_H

#include <stdint.h>
#include <stdbool.h>

typedef struct c610_raw_data {
    uint16_t raw_angle;
    int16_t raw_speed;
    int16_t raw_torque_current;

} c610_raw_data;

typedef struct c610_data {
    float angle;
    float speed;
    float torque_current;

    int16_t rotation_count;
    uint16_t prev_angle;
    uint16_t offset_angle;
    bool offset_initialized;

} c610_data;

#endif //ROBOMASTER_C610_DEF_H
