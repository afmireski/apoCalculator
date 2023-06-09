#include "calculator.hpp"
#include <sstream>
using namespace std;

class RegisterInterface
{
    virtual float getIntValue() = 0;

    virtual float getDecimalValue() = 0;

    virtual void countBits() = 0;

public:
    virtual void updateValue(int) = 0;

    virtual void setValue(string) = 0;

    virtual float getValue() = 0;

    virtual void setDecimalSeparator(bool) = 0;

    virtual bool hasDecimalSeparator() = 0;

    virtual Signal getSignal() = 0;

    virtual void setSignal(Signal) = 0;

    virtual void reset() = 0;
};

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

    void setValue(string);

    float getValue();

    void setDecimalSeparator(bool);

    bool hasDecimalSeparator();

    Signal getSignal();

    void setSignal(Signal);

    void reset();
};

class CpuAndreVictor : public Cpu
{
    Register *registerOne;
    Register *registerTwo;
    Register *memoryRegister;
    Operator operation;
    unsigned char writeIndex;
    bool on;

    bool isDoubleMemory;

    Display *display;

    int convertDigitToInt(Digit);

    void showResponseOnDisplay(string);

    void mPlus();

    void mMinus();

    void mrc();

    void setIsDoubleMemory(bool);

    bool getIsDoubleMemory();

    float calculate(Operator);

    float calculatePercentage(Operator, float, float);

    bool isOn();

    void setOn(bool = true);

public:
    CpuAndreVictor();

    ~CpuAndreVictor();

    void receive(Digit);
    void receive(Operator);
    void receive(Control);

    void setDisplay(Display *);
};