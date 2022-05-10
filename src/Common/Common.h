#pragma once

#include <Arduino.h>

enum ControlEventType : uint8_t {
    RotationMove,
    RotationMoveUp,
    RotationMoveDown,
    ButtonPressed,
    ButtonDown,
    ButtonUp
};

enum ValueChangeType : uint8_t {
    Nothing,
    Increase,
    Decrease
};