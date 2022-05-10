#include "KnobControlBase.h"

KnobControlBase::KnobControlBase() {
    this->acceleration = new KnobAcceleration();
}

void KnobControlBase::enable(bool e) {
    this->_enabled = e;
}

void KnobControlBase::set_callback(void (*callback)(ControlEventType event_type)) {
    this->_callback = callback;
    this->_callback_set = true;
}

void KnobControlBase::trigger_change(int32_t movement, uint32_t time_span) {
    float accel = this->acceleration->get_acceleration(time_span);
    ValueChangeType change_type = this->_do_change(movement, accel);
    if (this->_callback_set) {
        if (change_type == ValueChangeType::Increase) {
            this->_callback(ControlEventType::RotationMove);
            this->_callback(ControlEventType::RotationMoveUp);
        } else if (change_type == ValueChangeType::Decrease) {
            this->_callback(ControlEventType::RotationMove);
            this->_callback(ControlEventType::RotationMoveDown);
        }
    }
}

void KnobControlBase::trigger_button(bool button_state) {
    if (this->_callback_set) {
        if (button_state == LOW) {
            this->_callback(ControlEventType::ButtonDown);
        } else {
            this->_callback(ControlEventType::ButtonUp);
            this->_callback(ControlEventType::ButtonPressed);
        }
    }
}