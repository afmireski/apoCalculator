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
        virtual char const* getSymbol() = 0;
        virtual void setKeyboard(KeyboardInterface*) = 0;
};

class KeyDigitInterface: public KeyInterface {
    public:
        virtual Digit getDigit() = 0;
};

class KeyOperationInterface: public KeyInterface {
    public:
        virtual Operation getOperation() = 0;
};

class KeyControlInterface: public KeyInterface {
    public:
        virtual Control getControl() = 0;
};

class KeyboardInterface
{
public:
    virtual void receive(Digit) = 0;
    virtual void receive(Operation) = 0;
    virtual void receive(Control) = 0;

    virtual KeyInterface* getKey(Digit) = 0;
    virtual KeyInterface* getKey(Operation) = 0;
    virtual KeyInterface* getKey(Control) = 0;

    virtual void addKey(KeyInterface*) = 0;

    virtual void setCpu(CpuInterface*) = 0;
};

class CpuInterface
{
public:
    virtual void receive(Digit) = 0;
    virtual void receive(Operation) = 0;
    virtual void receive(Control) = 0;

    virtual void setDisplay(DisplayInterface*) = 0;
};

class DisplayInterface
{
public:
    virtual void show(Digit) = 0;
    virtual void clear() = 0;
};

class CalculatorInterface
{
public:
    virtual DisplayInterface *getDisplay() = 0;
    virtual void setDisplay() = 0;

    virtual CpuInterface *getCpu() = 0;
    virtual void *setCpu() = 0;

    virtual KeyboardInterface *getKeyboard() = 0;
    virtual void *setKeyboard() = 0;
};