#include "interfaces.hpp"

class Register : public RegisterInterface
{
    float intValue;
    float decimalValue;
    bool hasSeparator;
    Signal signal;

public:
    Register();

    ~Register();

    void updateValue(float);

    float getIntValue();

    float getDecimalValue();

    void setDecimalSeparator(bool);

    bool hasDecimalSeparator();

    Signal getSignal();

    void setSignal(Signal);

    void reset();
};

class Cpu : public CpuInterface
{
    Register* registerOne;
    Register* registerTwo;
    Register* memoryRegister;
    Operation operation;
    unsigned char writeIndex;

    DisplayInterface *display;

public:
    Cpu();

    ~Cpu();

    void receive(Digit);
    void receive(Operation);
    void receive(Control);

    void setDisplay(DisplayInterface *);
};