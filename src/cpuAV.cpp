#include "cpuAV.hpp"
#include "register.hpp"
#include <cstdlib>
#include <cmath>
#include <sstream>
using namespace std;

CpuAndreVictor::CpuAndreVictor()
{
    this->registerOne = new Register();
    this->registerTwo = new Register();
    this->memoryRegister = new Register();
    this->operation = SUM;
    this->writeIndex = 0;

    this->display = NULL;
}

CpuAndreVictor::~CpuAndreVictor()
{
    delete this->registerOne;
    delete this->registerTwo;
    delete this->memoryRegister;
    this->display = NULL;
}

int CpuAndreVictor::convertDigitToInt(Digit value)
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

void CpuAndreVictor::receive(Digit digit)
{
    if (this->display != NULL)
        this->display->add(digit);

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

void CpuAndreVictor::calculate(Operator operation)
{
    float valueOne = this->registerOne->getValue();
    float valueTwo = this->registerTwo->getValue();

    float response;
    switch (operation)
    {
    case SUM:
        response = valueOne + valueTwo;
        break;
    case SUBTRACTION:
        response = valueOne - valueTwo;
        break;
    case MULTIPLICATION:
        response = valueOne * valueTwo;
        break;
    case DIVISION:
        response = valueOne / valueTwo;
        break;
    case SQUARE_ROOT:
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

void CpuAndreVictor::receive(Operator operation)
{
    if (operation == SQUARE_ROOT)
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

void CpuAndreVictor::receive(Control control)
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
        this->display->addDecimalSeparator();
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
    case ON_CLEAR_ERROR:
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
            this->display->add(ZERO);
        }
        break;
    default:
        // Lançar exceção
        break;
    }
}

void CpuAndreVictor::setDisplay(Display *display)
{
    this->display = display;
    this->display->add(ZERO);
    this->display->clear();
}

void CpuAndreVictor::showResponseOnDisplay(string value)
{
    if (this->display != NULL)
    {
        this->display->clear();
        for (int i = 0; value[i] != '\0'; i++)
        {
            switch (value[i])
            {
            case '0':
                this->display->add(ZERO);
                break;
            case '1':
                this->display->add(ONE);
                break;
            case '2':
                this->display->add(TWO);
                break;
            case '3':
                this->display->add(THREE);
                break;
            case '4':
                this->display->add(FOUR);
                break;
            case '5':
                this->display->add(FIVE);
                break;
            case '6':
                this->display->add(SIX);
                break;
            case '7':
                this->display->add(SEVEN);
                break;
            case '8':
                this->display->add(EIGHT);
                break;
            case '9':
                this->display->add(NINE);
                break;
            case '.':
                this->display->addDecimalSeparator();
                break;
            case '-':
                this->display->setSignal(NEGATIVE);
                break;
            default:
                // Lançar uma exceção
                break;
            }
        }
        this->display->clear();
    }
}
