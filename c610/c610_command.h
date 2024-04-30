//
// Created by masafumi on 4/30/24.
//

#ifndef ROBOMASTER_C610_COMMAND_H
#define ROBOMASTER_C610_COMMAND_H

#include "stdint.h"

void set_raw_data(uint8_t RxData[], uint8_t id);

void processing_data(uint8_t id);

#endif //ROBOMASTER_C610_COMMAND_H
