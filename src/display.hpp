#include "interfaces.hpp"

class Display : public DisplayInterface
{
public:
    Display();

    ~Display();

    void show(Digit);

    void clear();
};