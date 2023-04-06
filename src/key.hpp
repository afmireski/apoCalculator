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