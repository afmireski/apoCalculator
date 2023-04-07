#include "interfaces.hpp"

class Calculator : CalculatorInterface
{
    DisplayInterface *display;

    CpuInterface *cpu;

    KeyboardInterface *keyboard;

public:
    Calculator();

    ~Calculator();

    DisplayInterface *getDisplay();
    void setDisplay(DisplayInterface*);

    CpuInterface *getCpu();
    void setCpu(CpuInterface*);

    KeyboardInterface *getKeyboard();
    void setKeyboard(KeyboardInterface*);
};