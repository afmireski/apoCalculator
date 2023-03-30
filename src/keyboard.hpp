#include "interfaces.hpp"
#include "key.hpp"

class Keyboard : public KeyboardInterface
{
    Key *keys;

public:
    Keyboard();

    ~Keyboard();

    float readNumber();

    Operation readOperation();
};
