#include "cpu.hpp"

Register::Register() {
    this->intValue = 0.0;
    this->decimalValue = 0.0;
    this->hasSeparator = false;
    this->signal = POSITIVE;
    this->bitLen = 1;
};

Register::~Register() {};

void Register::updateValue(float value) {
    if (this->hasDecimalSeparator()) {
        this->decimalValue = (this->decimalValue * 10.0) + value;
    } else {
        this->intValue = (this->intValue * 10.0) + value;
    }
    if (this->bitLen != 1 || value > 0) this->bitLen++;
};

float Register::getIntValue() {
    return this->intValue;
};

float Register::getDecimalValue() {
    float value = decimalValue;
    
    while(value > 0.0) value *= 0.1;

    return value;
};