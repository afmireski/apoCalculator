
// #include "calculator.hpp"
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// using namespace std;

// /**
//  * Keyboard
//  */
// Keyboard::Keyboard() {}

// Keyboard::~Keyboard() {}

// float Keyboard::readNumber()
// {
//     float input;
//     cin >> input;

//     return input;
// }

// Operation Keyboard::readOperation()
// {
//     unsigned short input;

//     cin >> input;

//     if (input > 6)
//         return Operation::AC;

//     return (Operation)input;
// }

// /**
//  * Cpu
//  */
// Cpu::Cpu()
// {
//     this->memory = new float[2];

//     this->ac();
// }

// Cpu::~Cpu()
// {
//     delete this->memory;
// }

// float Cpu::calculate()
// {
//     float response;

//     switch (this->operation)
//     {
//     case AC:
//         this->ac();
//         return 0;
//     case SUM:
//         response = this->memory[0] + this->memory[1];
//         break;

//     case SUB:
//         response = this->memory[0] - this->memory[1];
//         break;

//     case MLT:
//         response = this->memory[0] * this->memory[1];
//         break;

//     case DIV:
//         response = this->memory[0] / this->memory[1];
//         break;

//     case RAD:
//         response = sqrtf(this->memory[0]);
//         break;

//     default: // EQU
//         response = this->memory[0];
//         break;
//     }
//     this->memory[0] = response;
//     this->memory[1] = 0;
//     this->writeIndex = 1;

//     return response;
// }

// void Cpu::ac()
// {
//     for (int i = 0; i < 2; i++)
//         this->memory[i] = 0;

//     this->operation = Operation::SUM;

//     this->writeIndex = 0;
// }

// void Cpu::write(float value)
// {
//     this->memory[writeIndex] = value;

//     if (this->writeIndex == 1)
//     {
//         this->writeIndex = 0;
//     }
//     else
//     {
//         this->writeIndex = 1;
//     }
// }


// void Cpu::setOperation(Operation value) {
//     this->operation = value;
// }

// /**
//  * Display
//  */
// Display::Display() {}

// Display::~Display() {}

// void Display::showMessage(const char *message)
// {
//     cout << message;
// }

// void Display::showOperations()
// {
//     cout << "\nInforme a operação:\n";
//     cout << "0 - AC\n";
//     cout << "1 - Adição\n";
//     cout << "2 - Subtração\n";
//     cout << "3 - Multiplicação\n";
//     cout << "4 - Divisão\n";
//     cout << "5 - Radiciação\n";
//     cout << "6 - Igual\n";
//     cout << "> ";
// }

// void Display::showResult(float value)
// {
//     cout << fixed << setprecision(2) << value << "\n";
// }

// /**
//  * Calculator
//  */
// Calculator::Calculator()
// {
//     this->display = new Display();

//     this->keyboard = new Keyboard();

//     this->cpu = new Cpu();
// }

// Calculator::~Calculator()
// {
//     delete this->display;

//     delete this->keyboard;

//     delete this->cpu;
// }

// Display *Calculator::getDisplay()
// {
//     return this->display;
// }

// Keyboard *Calculator::getKeyboard()
// {
//     return this->keyboard;
// }

// Cpu *Calculator::getCpu()
// {
//     return this->cpu;
// }
