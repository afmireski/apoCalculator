#include "calculator.hpp"

int main(int argc, char const *argv[])
{
    Calculator calculator;

    float result = 0;
    float n;

    while (true)
    {
        calculator.getDisplay()->showMessage("Digite um número:\n");
        n = calculator.getKeyboard()->readNumber();

        calculator.getCpu()->write(n);

        calculator.getDisplay()->showOperations();

        Operation operation = calculator.getKeyboard()->readOperation();

        if (operation == Operation::EQU)
        {
            calculator.getDisplay()->showMessage("O resultado de suas operações é: ");
            calculator.getDisplay()->showResult(result);
            break;
        };

        result = calculator.getCpu()->calculate();

        calculator.getCpu()->setOperation(operation);
    }

    return 0;
}
