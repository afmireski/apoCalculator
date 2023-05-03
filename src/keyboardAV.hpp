#include "calculator.hpp"
#include <vector>

#include <vector>
class KeyboardAndreVictor : public Keyboard
{
    std::vector<Key *> keys;
    char keysCount;
    Cpu *cpu;

public:
    KeyboardAndreVictor();
    ~KeyboardAndreVictor();
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
    Key *getKey(Digit);
    Key *getKey(Operator);
    Key *getKey(Control);
    Key *getKey(Symbol);
    void add(Key *);
    void setCpu(Cpu *);
};
