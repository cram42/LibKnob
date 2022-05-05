#include "LibKnob.h"

Knob::Knob(RotaryEncoder* encoder) {
    this->_encoder = encoder;
}

void Knob::add_control(KnobControlBase* control) {
    this->_controls[this->_num_controls] = control;
    this->_num_controls++;
}

void Knob::begin() {

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
}