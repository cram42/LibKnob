#pragma once

#include <Arduino.h>
#include <RotaryEncoder.h>

#include "Common/Common.h"
#include "KnobControlBase/KnobControlBase.h"
#include "KnobControlI8/KnobControlI8.h"
#include "KnobControlU8/KnobControlU8.h"
#include "KnobControlI16/KnobControlI16.h"
#include "KnobControlU16/KnobControlU16.h"


class Knob {
    
    public:
        Knob(RotaryEncoder* encoder, uint8_t button_pin = -1);

        void add_control(KnobControlBase* control);
        void begin();
        void loop();

    private:
        RotaryEncoder* _encoder;
        bool _button_enabled = false;
        uint8_t _button_pin;
        bool _button_was = HIGH;

        KnobControlBase* _controls[10];
        uint8_t _num_controls = 0;

        int32_t _last_pos = 0;

};