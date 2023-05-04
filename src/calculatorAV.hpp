#include "calculator.hpp"

class CalculatorAndreVictor : public Calculator
{
    Display *display;

    Cpu *cpu;

    Keyboard *keyboard;

public:
    CalculatorAndreVictor();

    ~CalculatorAndreVictor();

    Display *getDisplay();
    void setDisplay(Display*);

    Cpu *getCpu();
    void setCpu(Cpu*);

    Keyboard *getKeyboard();
    void setKeyboard(Keyboard*);
};