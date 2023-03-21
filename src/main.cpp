#include "calculator.hpp"

int main(int argc, char const *argv[])
{
    Calculator calculator;

    float result = 0;
    while (true)
    {
        calculator.getDisplay()->showMessage("Digite um número:\n");

        float n = calculator.getKeyboard()->readNumber();

        calculator.getCpu()->write(n);

        calculator.getDisplay()->showOperations();

        Operation operation = calculator.getKeyboard()->readOperation();

        calculator.getCpu()->setOperation(operation);

        result = calculator.getCpu()->calculate();

        if (operation == Operation::EQU)
        {
            calculator.getDisplay()->showMessage("O resultado de suas operações é: ");
            calculator.getDisplay()->showResult(result);
            break;
        };
    }

    return 0;
}
