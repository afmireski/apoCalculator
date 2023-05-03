#include "../src/calculator.hpp"

class Test
{
public:
    virtual void begin() = 0;
    virtual void run() = 0;
    virtual void after() = 0;
};

class TestCalculatorBase : public Test
{
protected:
    Calculator *calculator;

public:
    TestCalculatorBase(Calculator *);

    void begin();
    void after();
    virtual char const *getName() = 0;
};

class TestSum : public TestCalculatorBase
{
public:
    TestSum(Calculator *);

    void run();
    char const *getName();
};

class TestSubtraction : public TestCalculatorBase
{
public:
    TestSubtraction(Calculator *);

    void run();
    char const *getName();
};

class TestMultiplication : public TestCalculatorBase
{
public:
    TestMultiplication(Calculator *);

    void run();
    char const *getName();
};

class TestDivision : public TestCalculatorBase
{
public:
    TestDivision(Calculator *);

    void run();
    char const *getName();
};

class TestSubtraction : public TestCalculatorBase
{
public:
    TestSubtraction(Calculator *);

    void run();
    char const *getName();
};

class TestRad : public TestCalculatorBase
{
public:
    TestRad(Calculator *);

    void run();
    char const *getName();
};

class TestePercentage : public TestCalculatorBase
{
public:
    TestePercentage(Calculator *);

    void run();
    char const *getName();
};
