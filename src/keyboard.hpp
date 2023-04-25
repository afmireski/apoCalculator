#include "interfaces.hpp"

class Keyboard : public KeyboardInterface
{
    KeyInterface **keys;

    CpuInterface* cpu;

public:
    Keyboard(KeyInterface **keys, CpuInterface* cpu);

    ~Keyboard();

    void receive(Digit);
    void receive(Operation);
    void receive(Control);

    KeyInterface *getKey(Digit);
    KeyInterface *getKey(Operation);
    KeyInterface *getKey(Control);

    void addKey(KeyInterface **);
    void setCpu(CpuInterface *);
};
