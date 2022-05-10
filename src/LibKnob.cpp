#include "LibKnob.h"

Knob::Knob(RotaryEncoder* encoder, uint8_t button_pin) {
    this->_encoder = encoder;
    if (button_pin != (uint8_t)(-1)) {
        this->_button_enabled = true;
        this->_button_pin = button_pin;
    }
}

void Knob::add_control(KnobControlBase* control) {
    this->_controls[this->_num_controls] = control;
    this->_num_controls++;
}

void Knob::begin() {
    if (this->_button_enabled) pinMode(this->_button_pin, INPUT);
    this->_button_was = digitalRead(this->_button_pin);
}

void Knob::loop() {
    this->_encoder->tick();
    int32_t change = this->_encoder->getPosition();

    if (change != 0) {
        uint32_t time_span = this->_encoder->getMillisBetweenRotations();
        for (uint8_t i = 0; i < this->_num_controls; i++) {
            this->_controls[i]->trigger_change(change, time_span);
        }
        this->_encoder->setPosition(0);
    }

    if (this->_button_enabled) {
        bool button_state = digitalRead(this->_button_pin);
        if (button_state != this->_button_was) {
            for (uint8_t i = 0; i < this->_num_controls; i++) {
                this->_controls[i]->trigger_button(button_state);
            }
            this->_button_was = button_state;
        }
    }
}