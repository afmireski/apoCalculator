#include "calculator.hpp"

class CalculatorErrorAndreVictor : public CalculatorError
{
  char const *message;

public:
  CalculatorErrorAndreVictor(char const *message);
  char const *getMessage();
};