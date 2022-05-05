#pragma once

#include <Arduino.h>
#include "../KnobControlBase/KnobControlBase.h"

class KnobControlU16 : public KnobControlBase {
    public:
        KnobControlU16(uint16_t* target, int16_t increment = 1, uint16_t min_limit = 0, uint16_t max_limit = UINT16_MAX);

        void set_increment(int16_t increment = 1);
        void set_max_limit(uint16_t max_limit = UINT16_MAX);
        void set_min_limit(uint16_t min_limit = 0);
        void set_rolling(bool rolling = true);
    
    protected:
        uint16_t* _target;
        int16_t _increment_size = 1;
        uint16_t _limit_max = UINT8_MAX;
        uint16_t _limit_min = 0;
        bool _rolling = false;

        void _do_change(int32_t movement, float acceleration);

};