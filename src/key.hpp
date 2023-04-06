#include "interfaces.hpp"
#include "keyboard.hpp"

class KeyDigit : public KeyDigitInterface
{
    Digit digit;

    char const* symbol;

    Keyboard* keyboard;

public:
    Key(char const* symbol, Digit digit, Keyboard* keyboard);

    ~Key();

    void press();

    char const* getSymbol();

    Digit getDigit();
};

class KeyOperation : public KeyOperationInterface
{
    Operation operation;

    char const* symbol;

    Keyboard* keyboard;

public:
    Key(char const* symbol, Operation operation, Keyboard* keyboard);

    ~Key();

    void press();

    char const* getSymbol();

    Operation getOperation();
};

class KeyControl : public KeyControlInterface
{
    Control control;

    char const* symbol;

    Keyboard* keyboard;

public:
    Key(char const* symbol, Control control, Keyboard* keyboard);

    ~Key();

    void press();

    char const* getSymbol();

    Control getControl();
};