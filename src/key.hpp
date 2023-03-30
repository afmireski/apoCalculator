#include "interfaces.hpp"

class Key : KeyInterface
{
    KeyValue value;

public:
    Key();

    ~Key();

    KeyValue press();
};