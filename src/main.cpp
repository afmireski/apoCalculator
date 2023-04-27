#include "display.hpp"
#include "key.hpp"
#include "keyboard.hpp"
#include "cpu.hpp"
#include "calculator.hpp"
#include "iostream"

int main(int argc, char const *argv[])
{    
    Cpu *cpu = new Cpu();
    Display* display = new Display();

    cpu->setDisplay(display);

    cpu->receive(TWO);
    cpu->receive(THREE);
    cpu->receive(FOUR); // 234

    cpu->receive(SUB); // +

    cpu->receive(FOUR);
    cpu->receive(DECIMAL_SEPARATOR);
    cpu->receive(FIVE);
    cpu->receive(THREE); //4.53

    cpu->receive(MLT); // *

    cpu->receive(TWO); // 2

    cpu->receive(EQUAL);

    delete cpu;
    delete display;

    return 0;
}
