#include "calculator.hpp"

class KeyboardAndreVictor : public Keyboard
{
    Key **keys;

    Cpu* cpu;

public:
    KeyboardAndreVictor(Key **keys, Cpu* cpu);

    ~KeyboardAndreVictor();

    void receive(Digit);
    void receive(Operator);
    void receive(Control);

    Key *getKey(Digit);
    Key *getKey(Operator);
    Key *getKey(Control);

    void addKey(Key **);
    void setCpu(Cpu *);
};
