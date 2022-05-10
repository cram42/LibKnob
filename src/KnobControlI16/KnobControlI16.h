#pragma once

#include <Arduino.h>
#include "../KnobControlBase/KnobControlBase.h"

class KnobControlI16 : public KnobControlBase {
    public:
        KnobControlI16(int16_t* target, int16_t increment = 1, int16_t min_limit = INT16_MIN, int16_t max_limit = INT16_MAX);

        void set_increment(int16_t increment = 1);
        void set_max_limit(int16_t max_limit = INT16_MAX);
        void set_min_limit(int16_t min_limit = INT16_MIN);
        void set_rolling(bool rolling = true);
    
    protected:
        int16_t* _target;
        int16_t _increment_size = 1;
        int16_t _limit_max = INT16_MAX;
        int16_t _limit_min = INT16_MIN;
        bool _rolling = false;

        ValueChangeType _do_change(int32_t movement, float acceleration);

};