#include <interfaces.hpp>

class Keyboard : KeyboardInterface
{
    Key* keys;


public:
    Keyboard();

    ~Keyboard();

    float readNumber();

    Operation readOperation();
};

class Cpu : CpuInterface
{
    float *memory;
    Operation operation;
    unsigned short writeIndex;

public:
    Cpu();

    ~Cpu();

    float calculate();

    void ac();

    void write(float value);

    void setOperation(Operation value);
};

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