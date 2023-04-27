#include "calculator.hpp";

class CalculatorAndreVictor : Calculator
{
    DisplayInterface *display;

    Cpu *cpu;

    Keyboard *keyboard;

public:
    CalculatorAndreVictor();

    ~CalculatorAndreVictor();

    DisplayInterface *getDisplay();
    void setDisplay(DisplayInterface*);

    Cpu *getCpu();
    void setCpu(Cpu*);

    Keyboard *getKeyboard();
    void setKeyboard(Keyboard*);
};