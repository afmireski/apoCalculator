#include "cpu.hpp"
#include <cstdlib>
#include <cmath>
#include <sstream>
using namespace std;

// -- Register --

Register::Register()
{
    this->reset();
}

Register::~Register() {}

void Register::updateValue(int value)
{
    if (this->hasDecimalSeparator())
    {
        this->decimalValue = (this->decimalValue * 10.0) + value;
    }
    else
    {
        this->intValue = (this->intValue * 10.0) + value;
    }
    if (this->bitLen == 1 && this->intValue == 0 && this->decimalValue == 0)
        return;
    this->bitLen++;
}

float Register::getIntValue()
{
    return this->intValue;
}

float Register::getDecimalValue()
{
    float value = this->decimalValue;

    while (((int)value / 1) > 0)
        value /= 10;

    return value;
}

void Register::setValue(string value)
{
    for (int i = 0; value[i] != '\0'; i++)
    {
        switch (value[i])
        {
        case '-':
            this->setSignal(NEGATIVE);
            break;
        case '.':
            this->setDecimalSeparator(true);
            break;
        case '0':
            this->updateValue(0);
            break;
        case '1':
            this->updateValue(1);
            break;
        case '2':
            this->updateValue(2);
            break;
        case '3':
            this->updateValue(3);
            break;
        case '4':
            this->updateValue(4);
            break;
        case '5':
            this->updateValue(5);
            break;
        case '6':
            this->updateValue(6);
            break;
        case '7':
            this->updateValue(7);
            break;
        case '8':
            this->updateValue(8);
            break;
        case '9':
            this->updateValue(9);
            break;
        }
    }
}

float Register::getValue()
{
    float value = this->getIntValue() + this->getDecimalValue();

    if (this->getSignal() == NEGATIVE)
    {
        return -value;
    }
    return value;
}

void Register::setDecimalSeparator(bool value)
{
    this->hasSeparator = value;
}

bool Register::hasDecimalSeparator()
{
    return this->hasSeparator;
}

Signal Register::getSignal()
{
    return this->signal;
}

void Register::setSignal(Signal value = NEGATIVE)
{
    this->signal = value;
}

void Register::reset()
{
    this->intValue = 0.0;
    this->decimalValue = 0.0;
    this->hasSeparator = false;
    this->signal = POSITIVE;
    this->bitLen = 1;
}

void Register::countBits()
{
    this->bitLen = 1;
    float intValue = this->getIntValue();
    if (intValue > 0)
    {
        this->bitLen = floor(log10f(intValue) + 1);
    }

    float decimalValue = this->getDecimalValue();
    if (decimalValue > 0)
    {
        this->bitLen += floor(log10f(intValue) + 1);
    }
}

// -- CPU --
Cpu::Cpu()
{
    this->registerOne = new Register();
    this->registerTwo = new Register();
    this->memoryRegister = new Register();
    this->operation = SUM;
    this->writeIndex = 0;

    this->display = NULL;
}

Cpu::~Cpu()
{
    delete this->registerOne;
    delete this->registerTwo;
    delete this->memoryRegister;
    this->display = NULL;
}

int Cpu::convertDigitToInt(Digit value)
{
    switch (value)
    {
    case ZERO:
        return 0;
    case ONE:
        return 1;
    case TWO:
        return 2;
    case THREE:
        return 3;
    case FOUR:
        return 4;
    case FIVE:
        return 5;
    case SIX:
        return 6;
    case SEVEN:
        return 7;
    case EIGHT:
        return 8;
    case NINE:
        return 9;
    default:
        return -1;
    }
}

void Cpu::receive(Digit digit)
{
    if (this->display != NULL)
        this->display->show(digit);

    int value = convertDigitToInt(digit);

    if (this->writeIndex == 0)
    {
        this->registerOne->updateValue(value);
    }
    else
    {
        this->registerTwo->updateValue(value);
    }
}

void Cpu::calculate(Operation operation)
{
    float valueOne = this->registerOne->getValue();
    float valueTwo = this->registerTwo->getValue();

    float response;
    switch (operation)
    {
    case SUM:
        response = valueOne + valueTwo;
        break;
    case SUB:
        response = valueOne - valueTwo;
        break;
    case MLT:
        response = valueOne * valueTwo;
        break;
    case DIV:
        response = valueOne / valueTwo;
        break;
    case RAD:
        // Exceção se for negativo
        response = sqrtf(this->writeIndex == 0 ? valueOne : valueTwo);
        break;
    default:
        // throw error
        break;
    }
    registerOne->reset();
    registerTwo->reset();
    this->writeIndex = 1;

    stringstream stream;
    stream << response;
    string convertValue = stream.str();

    registerOne->setValue(convertValue);
    this->showResponseOnDisplay(convertValue);
}

void Cpu::receive(Operation operation)
{
    if (operation == RAD)
    {
        this->calculate(operation);
        this->operation = SUM;
        
    }
    else
    {
        this->calculate(this->operation);
        this->operation = operation;
    }
}

void Cpu::receive(Control control)
{
    switch (control)
    {
    case DECIMAL_SEPARATOR:
        if (writeIndex == 0)
        {
            registerOne->setDecimalSeparator(true);
        }
        else
        {
            registerTwo->setDecimalSeparator(true);
        }
        this->display->showDecimalSeparator();
        break;
    case OFF:
        registerOne->reset();
        registerTwo->reset();
        this->operation = SUM;
        this->writeIndex = 0;
        break;
    case EQUAL:
        this->calculate(this->operation);
        break;
    case CE:
        if (this->writeIndex == 0)
        {
            this->registerOne->reset();
        }
        else
        {
            this->registerTwo->reset();
        }
        this->operation = SUM;
        if (this->display != NULL)
        {
            this->display->clear();
            this->display->show(ZERO);
        }
        break;
    default:
        // Lançar exceção
        break;
    }
}

void Cpu::setDisplay(DisplayInterface *display)
{
    this->display = display;
    this->display->show(ZERO);
    this->display->clear();
}

void Cpu::showResponseOnDisplay(string value)
{
    if (this->display != NULL)
    {
        this->display->clear();
        for (int i = 0; value[i] != '\0'; i++)
        {
            switch (value[i])
            {
            case '0':
                this->display->show(ZERO);
                break;
            case '1':
                this->display->show(ONE);
                break;
            case '2':
                this->display->show(TWO);
                break;
            case '3':
                this->display->show(THREE);
                break;
            case '4':
                this->display->show(FOUR);
                break;
            case '5':
                this->display->show(FIVE);
                break;
            case '6':
                this->display->show(SIX);
                break;
            case '7':
                this->display->show(SEVEN);
                break;
            case '8':
                this->display->show(EIGHT);
                break;
            case '9':
                this->display->show(NINE);
                break;
            case '.':
                this->display->showDecimalSeparator();
                break;
            case '-':
                this->display->showSignal();
                break;
            default:
                // Lançar uma exceção
                break;
            }
        }
        this->display->clear();
    }
}
