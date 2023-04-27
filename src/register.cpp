#include <cstdlib>
#include <cmath>
#include <sstream>
#include "register.hpp"

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
    if (this->bitLen == 1 && this->intValue == 0 && this->decimalValue == 0)
        return;
    this->bitLen++;
}

float Register::getIntValue()
{
    return this->intValue;
}

float Register::getDecimalValue()
{
    float value = this->decimalValue;

    while (((int)value / 1) > 0)
        value /= 10;

    return value;
}

void Register::setValue(string value)
{
    for (int i = 0; value[i] != '\0'; i++)
    {
        switch (value[i])
        {
        case '-':
            this->setSignal(NEGATIVE);
            break;
        case '.':
            this->setDecimalSeparator(true);
            break;
        case '0':
            this->updateValue(0);
            break;
        case '1':
            this->updateValue(1);
            break;
        case '2':
            this->updateValue(2);
            break;
        case '3':
            this->updateValue(3);
            break;
        case '4':
            this->updateValue(4);
            break;
        case '5':
            this->updateValue(5);
            break;
        case '6':
            this->updateValue(6);
            break;
        case '7':
            this->updateValue(7);
            break;
        case '8':
            this->updateValue(8);
            break;
        case '9':
            this->updateValue(9);
            break;
        }
    }
}

float Register::getValue()
{
    float value = this->getIntValue() + this->getDecimalValue();

    if (this->getSignal() == NEGATIVE)
    {
        return -value;
    }
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

void Register::countBits()
{
    this->bitLen = 1;
    float intValue = this->getIntValue();
    if (intValue > 0)
    {
        this->bitLen = floor(log10f(intValue) + 1);
    }

    float decimalValue = this->getDecimalValue();
    if (decimalValue > 0)
    {
        this->bitLen += floor(log10f(intValue) + 1);
    }
}