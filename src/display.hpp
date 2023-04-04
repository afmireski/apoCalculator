#include "interfaces.hpp"

class Display : public DisplayInterface
{
public:
    Display();

    ~Display();

    void showMessage(const char *message);

    void showOperations();

    void showResult(float value);
};