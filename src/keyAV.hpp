#pragma once

#include "calculator.hpp"

class KeyAndreVictor : public Key
{
    Symbol symbol;

    Keyboard *keyboard;

public:
    KeyAndreVictor(Symbol symbol);

    ~KeyAndreVictor();

    void press();

    Symbol getSymbol();

    void setKeyboard(Keyboard*);

};

class KeyDigitAndreVictor : public KeyDigit
{
    Digit digit;

    Symbol symbol;

    Keyboard *keyboard;

public:
    KeyDigitAndreVictor(Symbol symbol, Digit digit);
    ~KeyDigitAndreVictor();

    void press();

    Digit getDigit();

    void setKeyboard(Keyboard*);
};

class KeyOperatorAndreVictor : public KeyOperator
{
    Operator operation;

    Symbol symbol;

    Keyboard *keyboard;

public:
    KeyOperatorAndreVictor(Symbol symbol, Operator operation);

    ~KeyOperatorAndreVictor();

    void press();

    Operator getOperator();

    void setKeyboard(Keyboard*);
};

class KeyControlAndreVictor : public KeyControl
{
    Control control;

    Symbol symbol;

    Keyboard *keyboard;

public:
    KeyControlAndreVictor(Symbol symbol, Control control);

    ~KeyControlAndreVictor();

    void press();

    Control getControl();
    
    void setKeyboard(Keyboard*);
};