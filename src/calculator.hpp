
enum Operation
{
    AC = 0,
    SUM = 1,
    SUB = 2,
    MLT = 3,
    DIV = 4,
    RAD = 5,
    EQU = 6
};

class Keyboard
{
public:
    Keyboard();

    ~Keyboard();

    float readNumber();

    Operation readOperation();
};

class Cpu
{
    float *memory;
    Operation operation;
    unsigned char writeIndex;

public:
    Cpu();

    ~Cpu();

    float calculate();

    void ac();

    void write(float value);

    void setOperation(Operation value);
};

class Display
{
public:
    Display();

    ~Display();

    void showMessage(const char *message);

    void showOperations();

    void showResult(float value);
};

class Calculator
{
    Display* display;

    Cpu* cpu;

    Keyboard* keyboard;

public:
    Calculator();

    ~Calculator();

    Display *getDisplay();

    Cpu *getCpu();

    Keyboard *getKeyboard();
};