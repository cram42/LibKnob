#pragma once

#include <Arduino.h>
#include "../KnobAcceleration/KnobAcceleration.h"

class KnobControlBase {
    public:
        KnobAcceleration* acceleration;

        KnobControlBase();

        void enable(bool e = true);
        void set_callback(void (*callback)(int16_t change));
        void trigger_change(int32_t movement, uint32_t time_span);
    
    protected:
        bool _enabled = true;

        void (*_callback)(int16_t);
        bool _callback_set = false;
        
        virtual void _do_change(int32_t movement, float acceleration) = 0;
};