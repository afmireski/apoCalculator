#include "calculatorErrorAV.hpp"
#include "keyboardAV.hpp"
#include "keyAV.hpp"

KeyboardAndreVictor::KeyboardAndreVictor()
{
    this->keysCount = 0;
};

KeyboardAndreVictor::~KeyboardAndreVictor() {}

void KeyboardAndreVictor::receive(Digit digit)
{
    if (this->cpu != nullptr)
    {
        cpu->receive(digit);
    }
}

void KeyboardAndreVictor::receive(Operator operation)
{
    if (this->cpu != nullptr)
    {
        cpu->receive(operation);
    }
}

void KeyboardAndreVictor::receive(Control control)
{
    if (this->cpu != nullptr)
    {
        cpu->receive(control);
    }
}

Key *KeyboardAndreVictor::getKey(Digit digit)
{
    for (Key *key : this->keys)
        if (dynamic_cast<KeyDigit *>(key) && ((KeyDigit *)key)->getDigit() == digit)
            return key;
    throw new CalculatorErrorAndreVictor("Key with this digit not found!");
}

Key *KeyboardAndreVictor::getKey(Operator operation)
{
    for (Key *key : this->keys)
        if (dynamic_cast<KeyOperator *>(key) && ((KeyOperator *)key)->getOperator() == operation)
            return key;
    throw new CalculatorErrorAndreVictor("Key with this operation not found!");
}

Key *KeyboardAndreVictor::getKey(Control control)
{
    for (Key *key : this->keys)
        if (dynamic_cast<KeyControl *>(key) && ((KeyControl *)key)->getControl() == control)
            return key;
    throw new CalculatorErrorAndreVictor("Key with this control not found!");
}

Key *KeyboardAndreVictor::getKey(Symbol symbol) {
  for (Key *key : this->keys)
    if (key->getSymbol() == symbol)
      return key;
  throw new CalculatorErrorAndreVictor("Key with this symbol not found!");
}

void KeyboardAndreVictor::add(Key *key)
{
    if (key != nullptr)
    {
        this->keys.push_back(key);
        key->setKeyboard(this);
        this->keysCount++;
    }
}

// Define a CPU que receberá os comandos do teclado
void KeyboardAndreVictor::setCpu(Cpu *cpu)
{
    this->cpu = cpu;
}
