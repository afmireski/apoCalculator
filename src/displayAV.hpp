#include "calculator.hpp"

class DisplayAndreVictor : public Display
{
public:
    DisplayAndreVictor();

    ~DisplayAndreVictor();

    void add(Digit);

    void addDecimalSeparator();

    void setSignal(Signal);

    void clear();
};