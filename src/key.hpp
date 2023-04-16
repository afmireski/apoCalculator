#include "interfaces.hpp"

class Key : public KeyInterface
{
    char const *symbol;

    KeyboardInterface *keyboard;

public:
    Key(char const *symbol);

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

    char const *getSymbol();

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

    char const *getSymbol();

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

    char const *getSymbol();

    Control getControl();
    
    void setKeyboard(KeyboardInterface*);
};