#include "KnobAcceleration.h"

float KnobAcceleration::get_acceleration(uint16_t time_span_ms) {
    *t_prev_pos = time_span_ms;
    t_prev_pos += 1;
    if (t_prev_pos > &t_prev[2]) t_prev_pos = &t_prev[0];

    /*
    Serial.print(t_prev[0]); Serial.print(",");
    Serial.print(t_prev[1]); Serial.print(",");
    Serial.print(t_prev[2]); Serial.println();
    */

    time_span_ms = (t_prev[0] + t_prev[1] + t_prev[2]) / 3;

    if (time_span_ms > this->threshold_slow) return 1.0;
    if (time_span_ms < this->threshold_fast) return this->max_acceleration_multiplier;

    float t = time_span_ms;
    float t_fast = this->threshold_fast;                 //   5.0
    float t_slow = this->threshold_slow;                 // 100.0
    float a_min = 1.0;                                  //   1.0
    float a_max = this->max_acceleration_multiplier;    //  10.0

    // accel = ((t - t_slow) ^ 2 / (t_fast - t_slow) ^ 2) * (a_max - a_min) + a_min

    float accel = pow(t - t_slow, 2) / pow(t_fast - t_slow, 2) * (a_max - a_min) + a_min;

    /*
    Serial.print("ACCEL | ");
    Serial.print("t: "); Serial.print(t); Serial.print(" ");
    Serial.print("t_fast: "); Serial.print(t_fast); Serial.print(" ");
    Serial.print("t_slow: "); Serial.print(t_slow); Serial.print(" ");
    Serial.print("a_min: "); Serial.print(a_min); Serial.print(" ");
    Serial.print("a_max: "); Serial.print(a_max); Serial.print(" ");
    Serial.print("accel: "); Serial.print(accel); Serial.print(" ");
    Serial.println();
    */

    return accel;
}
