#include "keyboard.hpp"
#include "key.hpp"

Keyboard::Keyboard(KeyInterface **keys, CpuInterface* cpu) {

    this->keys = keys;
    this->cpu = cpu;

}

Keyboard::~Keyboard(){}

void Keyboard::receive(Digit digit) {
    if (cpu != nullptr) {
        cpu->receive(digit);
    }
}

void Keyboard::receive(Operation operation) {
    if (cpu != nullptr) {
        cpu->receive(operation);
    }
}

void Keyboard::receive(Control control) {
    if (cpu != nullptr) {
        cpu->receive(control);
    }
}

KeyInterface* Keyboard::getKey(Digit digit)
{
    for (int i = 0; i < sizeof(keys); i++){
        KeyDigit* keyDigit = dynamic_cast<KeyDigit*>(keys[i]);
        if (keyDigit && keyDigit->getDigit() == digit){
            return keys[i];
        }
    }
    return nullptr;
}

KeyInterface* Keyboard::getKey(Operation operation){
    for (int i = 0; i < sizeof(keys); i++){
    KeyOperation* keyOperation = dynamic_cast<KeyOperation*>(keys[i]);
    if (keyOperation && keyOperation->getOperation() == operation){
        return keys[i];
        }
    }
    return nullptr;
}

KeyInterface* Keyboard::getKey(Control control)
{
    for (int i = 0; i < sizeof(keys); i++){
        KeyControl* keyControl = dynamic_cast<KeyControl*>(keys[i]);
        if (keyControl && keyControl->getControl() == control){
            return keys[i];
        }
    }
    return nullptr;
}

void Keyboard::addKey(KeyInterface** key)
{
    this->keys = key;
}

// Define a CPU que receberá os comandos do teclado
void Keyboard::setCpu(CpuInterface *cpu) {
    this->cpu = cpu;
}
