#include "KnobControlI16.h"

KnobControlI16::KnobControlI16(int16_t* target, int16_t increment, int16_t min_limit, int16_t max_limit) : KnobControlBase() {
    this->_target = target;
    this->set_increment(increment);
    this->set_min_limit(min_limit);
    this->set_max_limit(max_limit);
    this->acceleration->max_acceleration_multiplier = 100.0;
}

void KnobControlI16::set_increment(int16_t increment) { this->_increment_size = increment; }
void KnobControlI16::set_max_limit(int16_t limit) { this->_limit_max = limit; }
void KnobControlI16::set_min_limit(int16_t limit) { this->_limit_min = limit; }
void KnobControlI16::set_rolling(bool rolling) { this->_rolling = rolling; }


void KnobControlI16::_do_change(int32_t movement, float acceleration) {
    if (!this->_enabled) return;
    int16_t change = movement * round((float)this->_increment_size * acceleration);
    int16_t current = *this->_target;

    if (!this->_rolling) {
        int16_t dist2min = this->_limit_min - current;
        dist2min = dist2min > 0 ? INT16_MIN : dist2min;
        int16_t dist2max = this->_limit_max - current;
        dist2max = dist2max < 0 ? INT16_MAX : dist2max;
        change = constrain(change, dist2min, dist2max);
    }

    *this->_target += change;
    if (this->_callback_set) this->_callback(change);
}
