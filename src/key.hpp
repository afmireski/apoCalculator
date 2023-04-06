#include "interfaces.hpp"

class Key : public KeyInterface
{
    char const *symbol;

    KeyboardInterface *keyboard;

public:
    Key(char const *symbol, KeyboardInterface *keyboard);

    ~Key();

    void press();

    char const *getSymbol();

};

class KeyDigit : public KeyDigitInterface
{
    Digit digit;

    char const *symbol;

    KeyboardInterface *keyboard;

public:
    KeyDigit(char const *symbol, Digit digit, KeyboardInterface *keyboard);

    ~KeyDigit();

    void press();

    char const *getSymbol();

    Digit getDigit();
};

class KeyOperation : public KeyOperationInterface
{
    Operation operation;

    char const *symbol;

    KeyboardInterface *keyboard;

public:
    KeyOperation(char const *symbol, Operation operation, KeyboardInterface *keyboard);

    ~KeyOperation();

    void press();

    char const *getSymbol();

    Operation getOperation();
};

class KeyControl : public KeyControlInterface
{
    Control control;

    char const *symbol;

    KeyboardInterface *keyboard;

public:
    KeyControl(char const *symbol, Control control, KeyboardInterface *keyboard);

    ~KeyControl();

    void press();

    char const *getSymbol();

    Control getControl();
};