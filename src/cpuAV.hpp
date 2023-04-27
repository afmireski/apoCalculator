#include "calculator.hpp"
#include "register.hpp"
#include <sstream>
using namespace std;

class CpuAndreVictor : public Cpu
{
    Register *registerOne;
    Register *registerTwo;
    Register *memoryRegister;
    Operator operation;
    unsigned char writeIndex;

    Display *display;

    int convertDigitToInt(Digit);

    void showResponseOnDisplay(string);

    void calculate(Operator);

public:
    CpuAndreVictor();

    ~CpuAndreVictor();

    void receive(Digit);
    void receive(Operator);
    void receive(Control);

    void setDisplay(Display *);
};