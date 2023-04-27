#include "calculator.hpp"

class KeyAndreVictor : public Key
{
    char const *symbol;

    Keyboard *keyboard;

public:
    KeyAndreVictor(char const *symbol);

    ~KeyAndreVictor();

    void press();

    char const *getSymbol();

    void setKeyboard(Keyboard*);

};

class KeyDigit : public KeyDigit
{
    Digit digit;

    char const *symbol;

    Keyboard *keyboard;

public:
    KeyDigit(char const *symbol, Digit digit);
    ~KeyDigit();

    void press();

    Digit getDigit();

    void setKeyboard(Keyboard*);
};

class KeyOperation : public KeyOperation
{
    Operator operation;

    char const *symbol;

    Keyboard *keyboard;

public:
    KeyOperation(char const *symbol, Operator operation);

    ~KeyOperation();

    void press();

    Operator getOperation();

    void setKeyboard(Keyboard*);
};

class KeyControl : public KeyControl
{
    Control control;

    char const *symbol;

    Keyboard *keyboard;

public:
    KeyControl(char const *symbol, Control control);

    ~KeyControl();

    void press();

    Control getControl();
    
    void setKeyboard(Keyboard*);
};