#include "interfaces.hpp"
#include "keyboard.hpp"
#include "cpu.hpp"
#include "display.hpp"

class Calculator : CalculatorInterface
{
    Display *display;

    Cpu *cpu;

    Keyboard *keyboard;

public:
    Calculator();

    ~Calculator();

    Display *getDisplay();

    Cpu *getCpu();

    Keyboard *getKeyboard();
};