#include "KnobControlBase.h"

KnobControlBase::KnobControlBase() {
    this->acceleration = new KnobAcceleration();
}

void KnobControlBase::enable(bool e) {
    this->_enabled = e;
}

void KnobControlBase::set_callback(void (*callback)(int16_t change)) {
    this->_callback = callback;
    this->_callback_set = true;
}

void KnobControlBase::trigger_change(int32_t movement, uint32_t time_span) {
    float accel = this->acceleration->get_acceleration(time_span);
    this->_do_change(movement, accel);
}