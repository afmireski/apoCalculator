#include "cpuAV.hpp"
#include "calculatorErrorAV.hpp"
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
    if (this->bitLen < 8)
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
    this->reset();
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
        default:
            throw new CalculatorErrorAndreVictor("This symbol cannot be converted!!!");
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

CpuAndreVictor::CpuAndreVictor()
{
    this->registerOne = new Register();
    this->registerTwo = new Register();
    this->memoryRegister = new Register();
    this->operation = SUM;
    this->writeIndex = 0;
    this->on = false;
    this->isDoubleMemory = false;

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
        throw new CalculatorErrorAndreVictor("DIGIT not implemented!!!");
    }
}

void CpuAndreVictor::receive(Digit digit)
{
    if (this->isOn())
    {
        if (this->getIsDoubleMemory())
            this->setIsDoubleMemory(false);
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
}

float CpuAndreVictor::calculatePercentage(Operator operation, float value, float per)
{
    switch (operation)
    {
    case SUM:
        return value + (value * per);
    case SUBTRACTION:
        return value - (value * per);
    case MULTIPLICATION:
        return value * per;
    case DIVISION:
        return value / per;
    default:
        throw new CalculatorErrorAndreVictor("This operation does not work with percentage!!!");
        break;
    }
}

float CpuAndreVictor::calculate(Operator operation)
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
        if (valueTwo == 0) throw new CalculatorErrorAndreVictor("Does exists division by zero!!!");
        
        response = valueOne / valueTwo;
        break;
    case SQUARE_ROOT:
    {
        float value;
        if (this->writeIndex == 0)
        {
            value = valueOne;
        }
        else
        {
            value = valueTwo;
        }

        if (value < 0)
        {
            throw new CalculatorErrorAndreVictor("Negative numbers do not have a square root.!!!");
        }
        response = sqrtf(value);
        break;
    }
    case PERCENTAGE:
    {
        float percentage = valueTwo / 100;

        response = calculatePercentage(this->operation, valueOne, percentage);
        break;
    }
    default:
        throw new CalculatorErrorAndreVictor("Operator not implemented!!!");
        break;
    }
    registerTwo->reset();
    this->writeIndex = 1;

    stringstream stream;
    stream << response;
    string convertValue = stream.str();

    registerOne->setValue(convertValue);
    this->showResponseOnDisplay(convertValue);

    return response;
}

void CpuAndreVictor::receive(Operator operation)
{
    if (this->isOn())
    {
        if (this->getIsDoubleMemory())
            this->setIsDoubleMemory(false);
        if (operation == SQUARE_ROOT)
        {
            this->calculate(operation);
            this->operation = SUM;
        }
        else if (operation == PERCENTAGE)
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
}

void CpuAndreVictor::receive(Control control)
{
    if (this->getIsDoubleMemory() && control != MEMORY_READ_CLEAR)
        this->setIsDoubleMemory(false);
    switch (control)
    {
    case DECIMAL_SEPARATOR:
        if (!this->isOn())
            break;

        if (writeIndex == 0 && !registerOne->hasDecimalSeparator())
        {
            registerOne->setDecimalSeparator(true);
            this->display->addDecimalSeparator();
        }
        else if (writeIndex == 1 && !registerTwo->hasDecimalSeparator())
        {
            registerTwo->setDecimalSeparator(true);
            this->display->addDecimalSeparator();
        }
        break;
    case OFF:
        if (!this->isOn())
            break;

        registerOne->reset();
        registerTwo->reset();
        this->operation = SUM;
        this->writeIndex = 0;
        this->setOn(false);
        break;
    case EQUAL:
        if (!this->isOn())
            break;

        this->calculate(this->operation);
        break;
    case ON_CLEAR_ERROR:
        if (!this->isOn())
        {
            this->setOn();
            this->display->add(ZERO);
            this->display->clear();
        }
        else
        {
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
        }
        break;
    case MEMORY_READ_CLEAR:
        this->mrc();
        break;
    case MEMORY_SUM:
        this->mPlus();
        break;
    case MEMORY_SUBTRACTION:
        this->mMinus();
        break;
    default:
        throw new CalculatorErrorAndreVictor("Control not implemented.!!!");
        break;
    }
}

void CpuAndreVictor::setDisplay(Display *display)
{
    this->display = display;
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
                throw new CalculatorErrorAndreVictor("This symbol cannot be showed!!!");
                break;
            }
        }
        this->display->clear();
    }
}

void CpuAndreVictor::mPlus()
{
    float value = calculate(this->operation);
    float memoryValue = this->memoryRegister->getValue();
    this->memoryRegister->setValue(to_string(memoryValue + value));
}

void CpuAndreVictor::mMinus()
{
    float value = calculate(this->operation);
    float memoryValue = this->memoryRegister->getValue();
    this->memoryRegister->setValue(to_string(memoryValue - value));
}

void CpuAndreVictor::mrc()
{
    if (this->getIsDoubleMemory())
    {
        this->memoryRegister->reset();
        this->setIsDoubleMemory(false);
    }
    else
    {
        float response = this->memoryRegister->getValue();
        stringstream stream;
        stream << response;
        string convertedValue = stream.str();
        this->showResponseOnDisplay(convertedValue);
        if (this->writeIndex == 0)
        {
            this->registerOne->setValue(convertedValue);
            this->writeIndex = 1;
        }
        else
        {
            this->registerTwo->setValue(convertedValue);
            this->writeIndex = 0;
        }
        this->setIsDoubleMemory(true);
    }
}

bool CpuAndreVictor::isOn()
{
    return this->on;
}

void CpuAndreVictor::setOn(bool value)
{
    this->on = value;
}

void CpuAndreVictor::setIsDoubleMemory(bool value)
{
    this->isDoubleMemory = value;
}

bool CpuAndreVictor::getIsDoubleMemory()
{
    return this->isDoubleMemory;
}
