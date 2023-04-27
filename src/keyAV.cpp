#include "keyAV.hpp"
#include <stddef.h>

KeyAndreVictor::KeyAndreVictor(char const *symbol)
{
    this->symbol = symbol;
};

KeyAndreVictor::~KeyAndreVictor(){};

void KeyAndreVictor::press(){};

char const *KeyAndreVictor::getSymbol()
{
    return this->symbol;
};

void KeyAndreVictor::setKeyboard(Keyboard *keyboard)
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

void KeyDigit::setKeyboard(Keyboard *keyboard)
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


void KeyOperation::setKeyboard(Keyboard *keyboard)
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


void KeyControl::setKeyboard(Keyboard *keyboard)
{
    this->keyboard = keyboard;
};

