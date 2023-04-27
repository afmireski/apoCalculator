#include "../src/displayAV.hpp"
#include "../src/keyAV.hpp"
#include "../src/keyboardAV.hpp"
#include "../src/cpuAV.hpp"
#include "../src/calculatorAV.hpp"
#include "iostream"

using namespace std;

void sumTest(CpuAndreVictor* cpu) {
    cout << "--- Teste Soma ---\n";
    cout << "543 + 856.962 = 1399.962\n\n";

    cpu->receive(FIVE);
    cpu->receive(FOUR);
    cpu->receive(THREE);

    cpu->receive(SUM);

    cpu->receive(EIGHT);
    cpu->receive(FIVE);
    cpu->receive(SIX);
    cpu->receive(DECIMAL_SEPARATOR);
    cpu->receive(NINE);
    cpu->receive(SIX);
    cpu->receive(TWO);

    cpu->receive(EQUAL);
    cpu->receive(OFF);
    cout << "--- Teste Soma ---\n";
}

void subTest(CpuAndreVictor* cpu) {
    cout << "--- Teste Subtração ---\n";
    cout << "9123.56 - 10000.124 = -876.564\n\n";

    cpu->receive(NINE);
    cpu->receive(ONE);
    cpu->receive(TWO);
    cpu->receive(THREE);
    cpu->receive(DECIMAL_SEPARATOR);
    cpu->receive(FIVE);
    cpu->receive(SIX);

    cpu->receive(SUBTRACTION);

    cpu->receive(ONE);
    cpu->receive(ZERO);
    cpu->receive(ZERO);
    cpu->receive(ZERO);
    cpu->receive(ZERO);
    cpu->receive(DECIMAL_SEPARATOR);
    cpu->receive(ONE);
    cpu->receive(TWO);
    cpu->receive(FOUR);

    cpu->receive(EQUAL);
    cpu->receive(OFF);
    cout << "--- Subtração ---\n";
}

void mltTest(CpuAndreVictor* cpu) {
    cout << "--- Teste Multiplicação ---\n";
    cout << "56.1 * 22.09 = 1239,249\n\n";

    cpu->receive(FIVE);
    cpu->receive(SIX);
    cpu->receive(DECIMAL_SEPARATOR);
    cpu->receive(ONE);

    cpu->receive(MULTIPLICATION);

    cpu->receive(TWO);
    cpu->receive(TWO);
    cpu->receive(DECIMAL_SEPARATOR);
    cpu->receive(ZERO);
    cpu->receive(NINE);

    cpu->receive(EQUAL);
    cpu->receive(OFF);
    cout << "--- Teste Multiplicação ---\n";
}

void divTest(CpuAndreVictor* cpu) {
    cout << "--- Teste Divisão ---\n";
    cout << "37 / 42.4 = 0,87264151\n\n";

    cpu->receive(THREE);
    cpu->receive(SEVEN);

    cpu->receive(DIVISION);

    cpu->receive(FOUR);
    cpu->receive(TWO);
    cpu->receive(DECIMAL_SEPARATOR);
    cpu->receive(TWO);

    cpu->receive(EQUAL);
    cpu->receive(OFF);
    cout << "--- Teste Divisão ---\n";
}

void radTest(CpuAndreVictor* cpu) {
    cout << "--- Teste Raiz ---\n";
    cout << "5 + \n";
    cout << "sqrt(37) = 6,0827625 \n\n";

    cpu->receive(FIVE);

    cpu->receive(SUM);

    cpu->receive(THREE);
    cpu->receive(SEVEN);

    cpu->receive(SQUARE_ROOT);

    cpu->receive(OFF);
    cout << "--- Teste Raiz ---\n";
}

int main()
{
    CpuAndreVictor *cpu = new CpuAndreVictor();
    DisplayAndreVictor* display = new DisplayAndreVictor();

    cpu->setDisplay(display);

    sumTest(cpu);
    subTest(cpu);
    mltTest(cpu);
    divTest(cpu);
    radTest(cpu);

    delete cpu;
    delete display;


    return 0;
}
