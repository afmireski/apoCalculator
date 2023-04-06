enum Operation
{
    SUM,
    SUB,
    MLT,
    DIV,
    RAD,
    PER,
};

enum Digit
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
};

enum Control {
    CE,
    MRC,
    M_LESS,
    M_PLUS,
    EQUAL,
    OFF,
};

class KeyInterface {
    public:
        virtual void press() = 0;
};

class KeyboardInterface
{
public:
    virtual float readNumber() = 0;

    virtual Operation readOperation() = 0;
};

class CpuInterface
{
public:
    virtual float calculate() = 0;

    virtual void ac() = 0;

    virtual void write(float value) = 0;

    virtual void setOperation(Operation value) = 0;
};

class DisplayInterface
{
public:
    virtual void showMessage(const char *message) = 0;

    virtual void showOperations() = 0;

    virtual void showResult(float value) = 0;
};

class CalculatorInterface
{
public:
    virtual DisplayInterface *getDisplay() = 0;

    virtual CpuInterface *getCpu() = 0;

    virtual KeyboardInterface *getKeyboard() = 0;
};