#include "calculator.hpp"
#include <iostream>
using namespace std;

/**
 * Keyboard
*/
Keyboard::Keyboard() {}

Keyboard::~Keyboard() {}

float Keyboard::readNumber() {
    float input;
    cin >> input;

    return input;
}

Operation Keyboard::readOperation() {
    unsigned char input;

    cin >> input;

    if (input > 6) return Operation::AC;

    return (Operation) input;
}


/**
 * Cpu
*/
Cpu::Cpu() {
    this->memory = new float[2];
    
    this->ac();
}

Cpu::~Cpu() {
    delete this->memory;    
}

float Cpu::calculate() {
    float response;

    switch (this->operation)
    {
    case SUM:
        response = this->memory[0] + this->memory[1];
        break;

    case SUB:
        response = this->memory[0] - this->memory[1];
        break;
    
    case MLT:
        response = this->memory[0] * this->memory[1];
        break;

    case DIV:
        response = this->memory[0] - this->memory[1];
        break;

    case RAD:
        response = this->memory[0] - this->memory[1];
        break;

    default: // EQU
        response = this->memory[0];
        break;
    }
    this->memory[0] = response;
    this->memory[1] = 0;

    return response;
}

void Cpu::ac() {
    for (int i = 0; i < 2; i++) this->memory[i] = 0;    

    this->operation = Operation::SUM;

    this->writeIndex = 0;
}

void Cpu::write(float value) {
    this->memory[writeIndex] = value;

    if (writeIndex == 1) {
        writeIndex = 0;
    } else {
        writeIndex = 1;
    }
}

/**
 * Display
*/


/**
 * Calculator
*/