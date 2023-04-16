#include "cpu.hpp"
#include <cstdlib>

// -- Register --

Register::Register()
{
    this->reset();
}

Register::~Register() {}

void Register::updateValue(int value)
{
    if (this->hasDecimalSeparator())
    {
        this->decimalValue = (this->decimalValue * 10.0) + value;
    }
    else
    {
        this->intValue = (this->intValue * 10.0) + value;
    }
    if (this->bitLen != 1 || value > 0)
        this->bitLen++;
}

float Register::getIntValue()
{
    return this->intValue;
}

float Register::getDecimalValue()
{
    float value = this->decimalValue;

    while (value > 0.0)
        value *= 0.1;

    return value;
}

void Register::setDecimalSeparator(bool value)
{
    this->hasSeparator = value;
}

bool Register::hasDecimalSeparator()
{
    return this->hasSeparator;
}

Signal Register::getSignal()
{
    return this->signal;
}

void Register::setSignal(Signal value = NEGATIVE)
{
    this->signal = value;
}

void Register::reset()
{
    this->intValue = 0.0;
    this->decimalValue = 0.0;
    this->hasSeparator = false;
    this->signal = POSITIVE;
    this->bitLen = 1;
}

// -- CPU --
Cpu::Cpu()
{
    this->registerOne = new Register();
    this->registerTwo = new Register();
    this->memoryRegister = new Register();
    this->operation = SUM;
    this->writeIndex = 0;

    this->display = NULL;
}

Cpu::~Cpu()
{
    delete this->registerOne;
    delete this->registerTwo;
    delete this->memoryRegister;
    this->display = NULL;
}

int Cpu::convertDigitToInt(Digit value)
{
    switch (value)
    {
    case ZERO:
        return 0;
    case ONE:
        return 1;
    case TWO:
        return 2;
    case THREE:
        return 3;
    case FOUR:
        return 4;
    case FIVE:
        return 5;
    case SIX:
        return 6;
    case SEVEN:
        return 7;
    case EIGHT:
        return 8;
    case NINE:
        return 9;
    }
}
