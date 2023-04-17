#include "interfaces.hpp"

class Register : public RegisterInterface
{
    float intValue;
    float decimalValue;
    bool hasSeparator;
    Signal signal;

    unsigned char bitLen;

    float getIntValue();

    float getDecimalValue();
    
    void countBits();

public:
    Register();

    ~Register();

    void updateValue(int);

    void setIntValue(int);

    void setDecimalValue(float);

    float getValue();

    void setDecimalSeparator(bool);

    bool hasDecimalSeparator();

    Signal getSignal();

    void setSignal(Signal);

    void reset();
};

class Cpu : public CpuInterface
{
    Register *registerOne;
    Register *registerTwo;
    Register *memoryRegister;
    Operation operation;
    unsigned char writeIndex;

    DisplayInterface *display;

    int convertDigitToInt(Digit);

    void calculate(Operation);

public:
    Cpu();

    ~Cpu();

    void receive(Digit);
    void receive(Operation);
    void receive(Control);

    void setDisplay(DisplayInterface *);
};