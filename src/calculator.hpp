#include <interfaces.hpp>

class Display : DisplayInterface
{
public:
    Display();

    ~Display();

    void showMessage(const char *message);

    void showOperations();

    void showResult(float value);
};

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