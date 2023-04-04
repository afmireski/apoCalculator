#include "interfaces.hpp"

class Key : public KeyInterface
{
    KeyValue value;

public:
    Key();

    ~Key();

    KeyValue press();
};