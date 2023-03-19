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


/**
 * Display
*/


/**
 * Calculator
*/