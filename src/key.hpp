#include "interfaces.hpp"

class Key : public KeyInterface
{
    char const *symbol;

    KeyboardInterface *keyboard;

public:
    Key(char const *symbol,KeyboardInterface *keyboard);

    ~Key();

    void press();

    char const *getSymbol();

    void setKeyboard(KeyboardInterface*);

};

class KeyDigit : public KeyDigitInterface
{
    Digit digit;

    char const *symbol;

    KeyboardInterface *keyboard;

public:
    KeyDigit(char const *symbol, Digit digit);
    ~KeyDigit();

    void press();

    Digit getDigit();

    void setKeyboard(KeyboardInterface*);
};

class KeyOperation : public KeyOperationInterface
{
    Operation operation;

    char const *symbol;

    KeyboardInterface *keyboard;

public:
    KeyOperation(char const *symbol, Operation operation);

    ~KeyOperation();

    void press();

    Operation getOperation();

    void setKeyboard(KeyboardInterface*);
};

class KeyControl : public KeyControlInterface
{
    Control control;

    char const *symbol;

    KeyboardInterface *keyboard;

public:
    KeyControl(char const *symbol, Control control);

    ~KeyControl();

    void press();

    Control getControl();
    
    void setKeyboard(KeyboardInterface*);
};