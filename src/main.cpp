#include "calculator.hpp"

int main(int argc, char const *argv[])
{
    Calculator calculator;


    float result;
    while (true) {
        calculator.getDisplay()->showMessage("Digite um número:\n");

        float n = calculator.getKeyboard()->readNumber();

        calculator.getCpu()->write(n);

        calculator.getDisplay()->showOperations();

        calculator.getKeyboard()->readOperation();

        calculator.getCpu()->calculate();
    }

    return 0;
}
