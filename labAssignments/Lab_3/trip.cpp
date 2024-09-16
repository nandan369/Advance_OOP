// trip.cpp
#include "trip.h"
#include <vector>
#include <cmath>     // for absolute value (if needed in future logic)

float moneyEqualizer(std::vector<float> expenses) {
    int n = expenses.size();
    if (n == 0) return 0.0f;

    // Calculate the total expense
    float total = 0.0f;
    for (size_t i = 0; i < expenses.size(); ++i) {
        total += expenses[i];
    }

    // Calculate the average expense per person
    float average = total / n;

    float toPay = 0.0f, toReceive = 0.0f;

    // Calculate how much needs to be paid or received by each person
    for (float expense : expenses) {
        if (expense < average) {
            // This person spent less than average, so they should receive money
            toReceive += (average - expense);
        } else if (expense > average) {
            // This person spent more than average, so they need to pay
            toPay += (expense - average);
        }
    }

    // Return the maximum of total amount to be paid or received
    // This ensures the minimum amount of money that needs to change hands
    return std::max(toPay, toReceive);
}
