//
// Created by masafumi on 4/30/24.
//

#include "c610_def.h"
#include "c610_command.h"

c610_raw_data _c610_raw_data[4] = {0};
c610_data _c610_data[4] = {0};

void set_raw_data(uint8_t RxData[], uint8_t id)
{
    _c610_raw_data[id].raw_angle = (uint16_t) (RxData[0] << 8 | RxData[1]);
    _c610_raw_data[id].raw_speed = (uint16_t) (RxData[2] << 8 | RxData[3]);
    _c610_raw_data[id].raw_torque_current = (uint16_t) (RxData[4] << 8 | RxData[5]);
}

void processing_data(uint8_t id)
{
    if (_c610_data[id].offset_initialized == false) {
        _c610_data[id].offset_angle = _c610_raw_data[id].raw_angle;
        _c610_data[id].prev_angle = _c610_raw_data[id].raw_angle;
        _c610_data[id].offset_initialized = true;
    }

    int16_t diff_angle = _c610_raw_data[id].raw_angle - _c610_data[id].prev_angle;
    if (diff_angle > 4096) {
        _c610_data[id].rotation_count--;
    } else if (diff_angle < -4096) {
        _c610_data[id].rotation_count++;
    }
    _c610_data[id].angle = _c610_data[id].rotation_count * 6.28318f + (_c610_raw_data[id].raw_angle - _c610_data[id].offset_angle) * 6.28318f / 8192;
    _c610_data[id].speed = _c610_raw_data[id].raw_speed;
    _c610_data[id].torque_current = _c610_raw_data[id].raw_torque_current;

    _c610_data[id].prev_angle = _c610_raw_data[id].raw_angle;
}