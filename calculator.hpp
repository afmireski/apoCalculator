class Keyboard
{
public:
    Keyboard();

    ~Keyboard();

    float readNumber();

    unsigned char readOperation();
};

class Cpu
{
    float *memory;
    unsigned char operation;
    unsigned char writeIndex;

public:
    Cpu();

    ~Cpu();

    float calculate();

    void ac();

    void write();
};

class Display
{
public:
    Display();

    ~Display();

    void showMessage(char *message);

    void showOperations();

    void showResult(float value);
};

class Calculator
{
    Display display;

    Cpu cpu;

    Keyboard keyboard;

public:
    Calculator();

    ~Calculator();

    Display getDisplay();

    Cpu getCpu();

    Keyboard getKeyboard();
};