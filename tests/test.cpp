#include "../src/displayAV.hpp"
#include "../src/keyAV.hpp"
#include "../src/keyboardAV.hpp"
#include "../src/cpuAV.hpp"
#include "../src/calculatorAV.hpp"
#include "../src/calculatorErrorAV.hpp"
#include "../src/calculator.hpp"
#include "iostream"

using namespace std;

void sumTest(Calculator *calc)
{
    try
    {
        cout << "--- Teste Soma ---\n";
        cout << "543 + 856.962 = 1399.962\n\n";
        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("5")->press();
        calc->getKeyboard()->getKey("4")->press();
        calc->getKeyboard()->getKey("3")->press();

        calc->getKeyboard()->getKey("+")->press();

        calc->getKeyboard()->getKey("8")->press();
        calc->getKeyboard()->getKey("5")->press();
        calc->getKeyboard()->getKey("6")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey("9")->press();
        calc->getKeyboard()->getKey("6")->press();
        calc->getKeyboard()->getKey("2")->press();

        calc->getKeyboard()->getKey("=")->press();
        calc->getKeyboard()->getKey("=")->press();
        calc->getKeyboard()->getKey("=")->press();
        calc->getKeyboard()->getKey("OFF")->press();
        cout << "--- Teste Soma ---\n";
    }
    catch (CalculatorErrorAndreVictor *e)
    {
        throw e;
    }
}

void subTest(Calculator *calc)
{
    try
    {
        cout << "--- Teste Subtração ---\n";
        cout << "9123.56 - 10000.124 = -876.564\n\n";
        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("9")->press();
        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("2")->press();
        calc->getKeyboard()->getKey("3")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey("5")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey("6")->press();
        calc->getKeyboard()->getKey(".")->press();

        calc->getKeyboard()->getKey("-")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();
        calc->getKeyboard()->getKey("0")->press();
        calc->getKeyboard()->getKey("0")->press();
        calc->getKeyboard()->getKey("0")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("2")->press();
        calc->getKeyboard()->getKey("4")->press();

        calc->getKeyboard()->getKey("=")->press();
        calc->getKeyboard()->getKey("OFF")->press();
        cout << "--- Subtração ---\n";
    }
    catch (CalculatorAndreVictor *e)
    {
        throw e;
    }
}

void mltTest(Calculator *calc)
{
    try
    {
        cout << "--- Teste Multiplicação ---\n";
        cout << "56.1 * 22.79 = 1278,519\n\n";
        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("5")->press();
        calc->getKeyboard()->getKey("6")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey("1")->press();

        calc->getKeyboard()->getKey("=")->press();
        calc->getKeyboard()->getKey("=")->press();
        calc->getKeyboard()->getKey("=")->press();

        calc->getKeyboard()->getKey("*")->press();

        calc->getKeyboard()->getKey("2")->press();
        calc->getKeyboard()->getKey("2")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey("7")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey("9")->press();

        calc->getKeyboard()->getKey("=")->press();
        calc->getKeyboard()->getKey("OFF")->press();
        cout << "--- Teste Multiplicação ---\n";
    }
    catch (CalculatorAndreVictor *e)
    {
        throw e;
    }
}

void divTest(Calculator *calc)
{
    try
    {
        cout << "--- Teste Divisão ---\n";
        cout << "37 / 42.4 = 0,87264151\n\n";
        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("3")->press();
        calc->getKeyboard()->getKey("7")->press();

        calc->getKeyboard()->getKey("/")->press();

        calc->getKeyboard()->getKey("4")->press();
        calc->getKeyboard()->getKey("2")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey(".")->press();
        calc->getKeyboard()->getKey("4")->press();

        calc->getKeyboard()->getKey("=")->press();
        calc->getKeyboard()->getKey("OFF")->press();
        cout << "--- Teste Divisão ---\n";
    }
    catch (CalculatorAndreVictor *e)
    {
        throw e;
    }
}

void radTest(Calculator *calc)
{
    try
    {
        cout << "--- Teste Raiz ---\n";
        cout << "5 + \n";
        cout << "sqrt(37) = 6,0827625 \n\n";
        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("5")->press();

        calc->getKeyboard()->getKey("+")->press();

        calc->getKeyboard()->getKey("3")->press();
        calc->getKeyboard()->getKey("7")->press();

        calc->getKeyboard()->getKey("¬")->press();

        calc->getKeyboard()->getKey("OFF")->press();
        cout << "--- Teste Raiz ---\n";
    }
    catch (CalculatorAndreVictor *e)
    {
        throw e;
    }
}

void percentageTest(Calculator *calc)
{
    try
    {
        cout << "--- Teste Porcentagem ---\n";
        cout << "100 + 10% = 110\n";
        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("+")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("%")->press();

        calc->getKeyboard()->getKey("OFF")->press();

        cout << "100 - 10% = 90\n";

        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("-")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("%")->press();

        calc->getKeyboard()->getKey("OFF")->press();

        cout << "100 * 10% = 10\n";

        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("*")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("%")->press();

        calc->getKeyboard()->getKey("OFF")->press();

        cout << "100 / 10% = 1000\n";

        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("/")->press();

        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("%")->press();

        calc->getKeyboard()->getKey("OFF")->press();
        cout << "--- Teste Porcentagem ---\n";
    }
    catch (CalculatorAndreVictor *e)
    {
        throw e;
    }
}

void memoryTest(Calculator *calc)
{
    try
    {
        cout << "--- Teste Memory ---\n";
        cout << "5 + 4 M+\n";
        cout << "M=9\n";
        cout << "9 - 10 = -1\n";
        cout << "M- -> 9 - -1 -> M = 10\n";
        cout << "MRC -> 10\n";
        cout << "MRC -> CLEAR\n";
        cout << "MRC -> 0\n";
        calc->getKeyboard()->getKey("ON/CE")->press();

        calc->getKeyboard()->getKey("5")->press();
        calc->getKeyboard()->getKey("+")->press();
        calc->getKeyboard()->getKey("4")->press();
        // calc->getKeyboard()->getKey("=")->press();

        calc->getKeyboard()->getKey("M+")->press();

        calc->getKeyboard()->getKey("-")->press();
        calc->getKeyboard()->getKey("1")->press();
        calc->getKeyboard()->getKey("0")->press();

        calc->getKeyboard()->getKey("=")->press();

        calc->getKeyboard()->getKey("M-")->press();

        calc->getKeyboard()->getKey("MRC")->press();
        calc->getKeyboard()->getKey("MRC")->press();
        calc->getKeyboard()->getKey("MRC")->press();

        calc->getKeyboard()->getKey("OFF")->press();        
        cout << "--- Teste Memory ---\n";
    }
    catch (CalculatorAndreVictor *e)
    {
        throw e;
    }
}

Calculator *buildCalculator()
{
    Calculator *calculator = new CalculatorAndreVictor();
    Cpu *cpu = new CpuAndreVictor();
    Display *display = new DisplayAndreVictor();
    Keyboard *keyboard = new KeyboardAndreVictor();

    KeyDigit *key0 = new KeyDigitAndreVictor("0", ZERO);
    KeyDigit *key1 = new KeyDigitAndreVictor("1", ONE);
    KeyDigit *key2 = new KeyDigitAndreVictor("2", TWO);
    KeyDigit *key3 = new KeyDigitAndreVictor("3", THREE);
    KeyDigit *key4 = new KeyDigitAndreVictor("4", FOUR);
    KeyDigit *key5 = new KeyDigitAndreVictor("5", FIVE);
    KeyDigit *key6 = new KeyDigitAndreVictor("6", SIX);
    KeyDigit *key7 = new KeyDigitAndreVictor("7", SEVEN);
    KeyDigit *key8 = new KeyDigitAndreVictor("8", EIGHT);
    KeyDigit *key9 = new KeyDigitAndreVictor("9", NINE);

    KeyOperator *keySum = new KeyOperatorAndreVictor("+", SUM);
    KeyOperator *keySub = new KeyOperatorAndreVictor("-", SUBTRACTION);
    KeyOperator *keyMlt = new KeyOperatorAndreVictor("*", MULTIPLICATION);
    KeyOperator *keyDiv = new KeyOperatorAndreVictor("/", DIVISION);
    KeyOperator *keySqt = new KeyOperatorAndreVictor("¬", SQUARE_ROOT);
    KeyOperator *keyPer = new KeyOperatorAndreVictor("%", PERCENTAGE);

    KeyControl *keyOnCe = new KeyControlAndreVictor("ON/CE", ON_CLEAR_ERROR);
    KeyControl *keyEqual = new KeyControlAndreVictor("=", EQUAL);
    KeyControl *keySeparator = new KeyControlAndreVictor(".", DECIMAL_SEPARATOR);
    KeyControl *keyOff = new KeyControlAndreVictor("OFF", OFF);
    KeyControl *keyMPlus = new KeyControlAndreVictor("M+", MEMORY_SUM);
    KeyControl *keyMLess = new KeyControlAndreVictor("M-", MEMORY_SUBTRACTION);
    KeyControl *keyMRC = new KeyControlAndreVictor("MRC", MEMORY_READ_CLEAR);

    keyboard->add(key0);
    keyboard->add(key1);
    keyboard->add(key2);
    keyboard->add(key3);
    keyboard->add(key4);
    keyboard->add(key5);
    keyboard->add(key6);
    keyboard->add(key7);
    keyboard->add(key8);
    keyboard->add(key9);

    keyboard->add(keySum);
    keyboard->add(keySub);
    keyboard->add(keyMlt);
    keyboard->add(keyDiv);
    keyboard->add(keySqt);
    keyboard->add(keyPer);

    keyboard->add(keyOnCe);
    keyboard->add(keyEqual);
    keyboard->add(keySeparator);
    keyboard->add(keyOff);
    keyboard->add(keyMPlus);
    keyboard->add(keyMLess);
    keyboard->add(keyMRC);

    keyboard->setCpu(cpu);

    cpu->setDisplay(display);
    calculator->setDisplay(display);
    calculator->setCpu(cpu);
    calculator->setKeyboard(keyboard);

    return calculator;
}

int main()
{

    Calculator *calc = buildCalculator();

    try
    {
        sumTest(calc);
        subTest(calc);
        mltTest(calc);
        divTest(calc);
        radTest(calc);
        percentageTest(calc);
        memoryTest(calc);
    }
    catch (CalculatorError *e)
    {
        cout << e->getMessage() << "\n";
    }
    delete calc->getCpu();
    delete calc->getDisplay();
    delete calc->getKeyboard();
    delete calc;

    return 0;
}
