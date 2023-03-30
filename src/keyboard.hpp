#include "interfaces.hpp"
#include "key.hpp"

class Keyboard : KeyboardInterface
{
    Key *keys;

public:
    Keyboard();

    ~Keyboard();

    float readNumber();

    Operation readOperation();
};
