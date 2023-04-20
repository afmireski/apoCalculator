#include "key.hpp"
#include <stddef.h>

Key::Key(char const *symbol,KeyboardInterface *keyboard)
{
    this->symbol = symbol;
};

Key::~Key(){};

void Key::press(){};

char const *Key::getSymbol()
{
    return this->symbol;
};

void Key::setKeyboard(KeyboardInterface *keyboard)
{
    this->keyboard = keyboard;
};

KeyDigit::KeyDigit(char const *symbol, Digit digit){
    this->digit = digit;
    this->symbol = symbol;

};

KeyDigit::~KeyDigit(){};

 void KeyDigit::press(){
    if (this->keyboard != NULL)
    {
        this->keyboard->receive(this->digit);
    }
 }

 Digit KeyDigit::getDigit(){

    return this->digit;
 }

void KeyDigit::setKeyboard(KeyboardInterface *keyboard)
{
    this->keyboard = keyboard;
};


KeyOperation::KeyOperation(char const *symbol, Operation operation){
    this->operation = operation;
    this->symbol = symbol;

};

KeyOperation::~KeyOperation(){};

 void KeyOperation::press(){

    if (this->keyboard != NULL)
    {
        this->keyboard->receive(this->operation);
    }

 }

 Operation KeyOperation::getOperation(){

    return this->operation;
 }


void KeyOperation::setKeyboard(KeyboardInterface *keyboard)
{
    this->keyboard = keyboard;
};

KeyControl::KeyControl(char const *symbol, Control control){
    this->control = control;
    this->symbol = symbol;

};

KeyControl::~KeyControl(){};

 void KeyControl::press(){

    if (this->keyboard != NULL)
    {
        this->keyboard->receive(this->control);
    }

 }

 Control KeyControl::getControl(){

    return this->control;
 }


void KeyControl::setKeyboard(KeyboardInterface *keyboard)
{
    this->keyboard = keyboard;
};

