#include "KnobControlI8.h"

KnobControlI8::KnobControlI8(int8_t* target, int8_t increment, int8_t min_limit, int8_t max_limit) : KnobControlBase() {
    this->_target = target;
    this->set_increment(increment);
    this->set_min_limit(min_limit);
    this->set_max_limit(max_limit);
    this->acceleration->max_acceleration_multiplier = 10.0;
}

void KnobControlI8::set_increment(int8_t increment) { this->_increment_size = increment; }
void KnobControlI8::set_max_limit(int8_t limit) { this->_limit_max = limit; }
void KnobControlI8::set_min_limit(int8_t limit) { this->_limit_min = limit; }
void KnobControlI8::set_rolling(bool rolling) { this->_rolling = rolling; }


void KnobControlI8::_do_change(int32_t movement, float acceleration) {
    if (!this->_enabled) return;
    int8_t change = movement * round((float)this->_increment_size * acceleration);
    int8_t current = *this->_target;

    if (!this->_rolling) {
        int8_t dist2min = this->_limit_min - current;
        dist2min = dist2min > 0 ? INT8_MIN : dist2min;
        int8_t dist2max = this->_limit_max - current;
        dist2max = dist2max < 0 ? INT8_MAX : dist2max;
        change = constrain(change, dist2min, dist2max);
    }

    *this->_target += change;
    if (this->_callback_set) this->_callback(change);
}
