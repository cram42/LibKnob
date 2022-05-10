#pragma once

#include <Arduino.h>
#include "../KnobControlBase/KnobControlBase.h"

class KnobControlI8 : public KnobControlBase {
    public:
        KnobControlI8(int8_t* target, int8_t increment = 1, int8_t min_limit = INT8_MIN, int8_t max_limit = INT8_MAX);

        void set_increment(int8_t increment = 1);
        void set_max_limit(int8_t max_limit = INT8_MAX);
        void set_min_limit(int8_t min_limit = INT8_MIN);
        void set_rolling(bool rolling = true);
    
    protected:
        int8_t* _target;
        int8_t _increment_size = 1;
        int8_t _limit_max = INT8_MAX;
        int8_t _limit_min = INT8_MIN;
        bool _rolling = false;

        ValueChangeType _do_change(int32_t movement, float acceleration);

};