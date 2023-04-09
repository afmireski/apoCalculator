#include "interfaces.hpp"

class Cpu : public CpuInterface
{
    float *memory;
    Operation operation;
    unsigned short writeIndex;

    DisplayInterface* display;

public:
    Cpu();

    ~Cpu();

    void receive(Digit);
    void receive(Operation);
    void receive(Control);

    void setDisplay(DisplayInterface*);
};