class Keyboard
{
public:
    Keyboard();

    ~Keyboard();

    float readNumber();

    unsigned char readOperation();
};

enum Operation {
    AC = 0,
    SUM = 1,
    SUB = 2,
    MLT = 3,
    DIV = 4,
    RAD = 5,
    EQU = 6
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

    Display& getDisplay();

    Cpu& getCpu();

    Keyboard& getKeyboard();
};