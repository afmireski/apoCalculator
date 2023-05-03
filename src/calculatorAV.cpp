#include "calculatorAV.hpp"

CalculatorAndreVictor::CalculatorAndreVictor(){};

CalculatorAndreVictor::~CalculatorAndreVictor(){};

Display *CalculatorAndreVictor::getDisplay()
{
    return this->display;
};

void CalculatorAndreVictor::setDisplay(Display *value)
{
    this->display = value;
};

Cpu *CalculatorAndreVictor::getCpu()
{
    return this->cpu;
};

void CalculatorAndreVictor::setCpu(Cpu *value)
{
    this->cpu = value;
};

Keyboard *CalculatorAndreVictor::getKeyboard()
{
    return this->keyboard;
};

void CalculatorAndreVictor::setKeyboard(Keyboard *value)
{
    this->keyboard = value;
};
