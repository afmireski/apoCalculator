#include "keyboardAV.hpp"
#include "keyAV.hpp"

KeyboardAndreVictor::KeyboardAndreVictor(Key **keys, Cpu* cpu) {

    this->keys = keys;
    this->cpu = cpu;

}

KeyboardAndreVictor::~KeyboardAndreVictor(){}

void KeyboardAndreVictor::receive(Digit digit) {
    if (cpu != nullptr) {
        cpu->receive(digit);
    }
}

void KeyboardAndreVictor::receive(Operator operation) {
    if (cpu != nullptr) {
        cpu->receive(operation);
    }
}

void KeyboardAndreVictor::receive(Control control) {
    if (cpu != nullptr) {
        cpu->receive(control);
    }
}

Key* KeyboardAndreVictor::getKey(Digit digit)
{
    for (int i = 0; i < sizeof(keys); i++){
        KeyDigit* keyDigit = dynamic_cast<KeyDigit*>(keys[i]);
        if (keyDigit && keyDigit->getDigit() == digit){
            return keys[i];
        }
    }
    return nullptr;
}

Key* KeyboardAndreVictor::getKey(Operator operation){
    for (int i = 0; i < sizeof(keys); i++){
    KeyOperator* keyOperator = dynamic_cast<KeyOperator*>(keys[i]);
    if (keyOperator && keyOperator->getOperator() == operation){
        return keys[i];
        }
    }
    return nullptr;
}

Key* KeyboardAndreVictor::getKey(Control control)
{
    for (int i = 0; i < sizeof(keys); i++){
        KeyControlAndreVictor* keyControl = dynamic_cast<KeyControlAndreVictor*>(keys[i]);
        if (keyControl && keyControl->getControl() == control){
            return keys[i];
        }
    }
    return nullptr;
}

void KeyboardAndreVictor::addKey(Key** key)
{
    this->keys = key;
}

// Define a CPU que receberá os comandos do teclado
void KeyboardAndreVictor::setCpu(Cpu *cpu) {
    this->cpu = cpu;
}
