#include <sstream>
#include "calculator.hpp"

#ifndef RegisterH
#define RegisterH
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
#endif


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