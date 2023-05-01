#include "calculatorErrorAV.hpp"

CalculatorErrorAndreVictor::CalculatorErrorAndreVictor(char const *message) {
  this->message = message;
}

char const *CalculatorErrorAndreVictor::getMessage() { return this->message; }