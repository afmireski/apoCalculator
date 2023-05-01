#include "displayAV.hpp"
#include <iostream>

using namespace std;

DisplayAndreVictor::DisplayAndreVictor() {};

DisplayAndreVictor::~DisplayAndreVictor() {};

void DisplayAndreVictor::add(Digit digit) {
    switch (digit)
    {
    case ZERO:
        cout << "0";
        break;
    case ONE:
        cout << "1";
        break;    
    case TWO:
        cout << "2";
        break;
    case THREE:
        cout << "3";
        break;
    case FOUR:
        cout << "4";
        break;
    case FIVE:
        cout << "5";
        break;    
    case SIX:
        cout << "6";
        break;
    case SEVEN:
        cout << "7";
        break;    
    case EIGHT:
        cout << "8";
        break;
    case NINE:
        cout << "9";
        break; 
    default:
        cout << "E";
    }
}

void DisplayAndreVictor::addDecimalSeparator() {
    cout << ".";
}

void DisplayAndreVictor::setSignal(Signal signal) {
    if (signal == NEGATIVE) cout << "-";
}

void DisplayAndreVictor::clear() {
    cout << "\n";
}
