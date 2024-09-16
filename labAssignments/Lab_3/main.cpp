// main.cpp
#include <iostream>
#include "trip.h"
#include <vector>

int main() {
    std::vector<float> expenses = {10.00, 20.00, 30.00};
    float result = moneyEqualizer(expenses);

    std::cout << "Minimum amount of money that needs to change hands: $" << result << std::endl;

    return 0;
}
