#pragma once

#include <Arduino.h>
#include "../KnobAcceleration/KnobAcceleration.h"
#include "../Common/Common.h"

class KnobControlBase {
    public:
        KnobAcceleration* acceleration;

        KnobControlBase();

        void enable(bool e = true);
        void set_callback(void (*callback)(ControlEventType event_type));
        void trigger_change(int32_t movement, uint32_t time_span);
        void trigger_button(bool button_state);
    
    protected:
        bool _enabled = true;

        void (*_callback)(ControlEventType);
        bool _callback_set = false;
        
        virtual ValueChangeType _do_change(int32_t movement, float acceleration) = 0;
};