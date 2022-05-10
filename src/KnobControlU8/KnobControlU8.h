#pragma once

#include <Arduino.h>
#include "../KnobControlBase/KnobControlBase.h"

class KnobControlU8 : public KnobControlBase {
    public:
        KnobControlU8(uint8_t* target, int8_t increment = 1, uint8_t min_limit = 0, uint8_t max_limit = UINT8_MAX);

        void set_increment(int8_t increment = 1);
        void set_max_limit(uint8_t max_limit = UINT8_MAX);
        void set_min_limit(uint8_t min_limit = 0);
        void set_rolling(bool rolling = true);
    
    protected:
        uint8_t* _target;
        int8_t _increment_size = 1;
        uint8_t _limit_max = UINT8_MAX;
        uint8_t _limit_min = 0;
        bool _rolling = false;

        ValueChangeType _do_change(int32_t movement, float acceleration);

};