#include "interfaces.hpp"

class Cpu : public CpuInterface
{
    float *memory;
    Operation operation;
    unsigned short writeIndex;

public:
    Cpu();

    ~Cpu();

    float calculate();

    void ac();

    void write(float value);

    void setOperation(Operation value);
};