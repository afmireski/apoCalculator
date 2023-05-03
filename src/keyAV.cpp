#include "keyAV.hpp"
#include <stddef.h>

KeyDigitAndreVictor::KeyDigitAndreVictor(Symbol symbol, Digit digit)
{
    this->digit = digit;
    this->symbol = symbol;
};

KeyDigitAndreVictor::~KeyDigitAndreVictor(){};

void KeyDigitAndreVictor::press()
{
    if (this->keyboard != NULL)
    {
        this->keyboard->receive(this->digit);
    }
}

Digit KeyDigitAndreVictor::getDigit()
{
    return this->digit;
}

void KeyDigitAndreVictor::setKeyboard(Keyboard *keyboard)
{
    this->keyboard = keyboard;
};

KeyOperatorAndreVictor::KeyOperatorAndreVictor(Symbol symbol, Operator operation)
{
    this->operation = operation;
    this->symbol = symbol;
};

KeyOperatorAndreVictor::~KeyOperatorAndreVictor(){};

void KeyOperatorAndreVictor::press()
{
    if (this->keyboard != NULL)
    {
        this->keyboard->receive(this->operation);
    }
}

Operator KeyOperatorAndreVictor::getOperator()
{
    return this->operation;
}

void KeyOperatorAndreVictor::setKeyboard(Keyboard *keyboard)
{
    this->keyboard = keyboard;
};

KeyControlAndreVictor::KeyControlAndreVictor(Symbol symbol, Control control)
{
    this->control = control;
    this->symbol = symbol;
};

KeyControlAndreVictor::~KeyControlAndreVictor(){};

void KeyControlAndreVictor::press()
{
    if (this->keyboard != NULL)
    {
        this->keyboard->receive(this->control);
    }
}

Control KeyControlAndreVictor::getControl()
{
    return this->control;
}

void KeyControlAndreVictor::setKeyboard(Keyboard *keyboard)
{
    this->keyboard = keyboard;
};
