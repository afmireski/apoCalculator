#pragma once

#include "calculator.hpp"

class KeyDigitAndreVictor : public KeyDigit
{
    Symbol symbol;
    Digit digit;
    Keyboard *keyboard;

public:
    KeyDigitAndreVictor(Symbol, Digit);
    ~KeyDigitAndreVictor();
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard *);
    Digit getDigit();
};

class KeyControlAndreVictor : public KeyControl
{
    Symbol symbol;
    Control control;
    Keyboard *keyboard;

public:
    KeyControlAndreVictor(Symbol, Control);
    ~KeyControlAndreVictor();
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard *);
    Control getControl();
};

class KeyOperatorAndreVictor : public KeyOperator
{
    Symbol symbol;
    Operator operation;
    Keyboard *keyboard;

public:
    KeyOperatorAndreVictor(Symbol, Operator);
    ~KeyOperatorAndreVictor();
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard *);
    Operator getOperator();
};