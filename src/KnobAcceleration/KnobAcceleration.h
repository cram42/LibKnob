#pragma once

#include <Arduino.h>

class KnobAcceleration {
    public:
        bool enabled = false;
        uint32_t threshold_slow = 100;
        uint32_t threshold_fast = 5;
        float max_acceleration_multiplier = 10.0;

        float get_acceleration(uint16_t time_span_ms);
    
    private:
        uint32_t t_prev[3] = { 0, 0, 0 };
        uint32_t* t_prev_pos = &t_prev[0];
};