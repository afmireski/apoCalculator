#include <sstream>
using namespace std;

#ifndef OperationH
#define OperationH
enum Operation
{
    SUM,
    SUB,
    MLT,
    DIV,
    RAD,
    PER,
};
#endif

#ifndef DigitH
#define DigitH
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
#endif

#ifndef ControlH
#define ControlH
enum Control
{
    CE,
    MRC,
    M_LESS,
    M_PLUS,
    EQUAL,
    OFF,
    DECIMAL_SEPARATOR
};
#endif

#ifndef SignalH
#define SignalH
enum Signal
{
    POSITIVE,
    NEGATIVE
};
#endif

class KeyboardInterface;

#ifndef DisplayH
#define DisplayH
class DisplayInterface
{
public:
    virtual void show(Digit) = 0;
    virtual void showDecimalSeparator() = 0;
    virtual void showSignal() = 0;
    virtual void clear() = 0;
};
#endif

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

#ifndef CpuH
#define CpuH
class CpuInterface
{
    virtual int convertDigitToInt(Digit) = 0;
    
    virtual void showResponseOnDisplay(string) = 0;

    virtual void calculate(Operation) = 0;

public:
    virtual void receive(Digit) = 0;
    virtual void receive(Operation) = 0;
    virtual void receive(Control) = 0;

    virtual void setDisplay(DisplayInterface *) = 0;
};
#endif

#ifndef KeyH
#define KeyH
class KeyInterface
{
public:
    virtual void press() = 0;
    virtual char const *getSymbol() = 0;
    virtual void setKeyboard(KeyboardInterface *) = 0;
};
#endif

#ifndef KeyDigitH
#define KeyDigitH
class KeyDigitInterface : public KeyInterface
{
public:
    virtual Digit getDigit() = 0;
};
#endif

#ifndef KeyOpeationH
#define KeyOpeationH
class KeyOperationInterface : public KeyInterface
{
public:
    virtual Operation getOperation() = 0;
};
#endif

#ifndef KeyControlH
#define KeyControlH
class KeyControlInterface : public KeyInterface
{
public:
    virtual Control getControl() = 0;
};
#endif

#ifndef KeyboardH
#define KeyboardH
class KeyboardInterface
{
public:
    virtual void receive(Digit) = 0;
    virtual void receive(Operation) = 0;
    virtual void receive(Control) = 0;

    virtual KeyInterface *getKey(Digit) = 0;
    virtual KeyInterface *getKey(Operation) = 0;
    virtual KeyInterface *getKey(Control) = 0;

    virtual void addKey(KeyInterface *) = 0;

    virtual void setCpu(CpuInterface *) = 0;
};
#endif

#ifndef CalculatorH
#define CalculatorH
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
#endif