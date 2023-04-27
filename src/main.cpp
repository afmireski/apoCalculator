#include "displayAV.hpp"
#include "keyAV.hpp"
#include "keyboardAV.hpp"
#include "cpuAV.hpp"
#include "calculator.hpp"
#include "iostream"

int main(int argc, char const *argv[])
{    
    CpuAndreVictor *cpu = new CpuAndreVictor();
    DisplayAndreVictor* display = new DisplayAndreVictor();

    cpu->setDisplay(display);

    cpu->receive(TWO);
    cpu->receive(THREE);
    cpu->receive(FOUR); // 234

    cpu->receive(SUBTRACTION); // +

    cpu->receive(FOUR);
    cpu->receive(DECIMAL_SEPARATOR);
    cpu->receive(FIVE);
    cpu->receive(THREE); //4.53

    cpu->receive(MULTIPLICATION); // *

    cpu->receive(TWO); // 2

    cpu->receive(EQUAL);

    delete cpu;
    delete display;

    return 0;
}
