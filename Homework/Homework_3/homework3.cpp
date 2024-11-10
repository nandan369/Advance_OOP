#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

/* --------------------------------------------------------
 * Function: HW3_02
 * Usage: HW3_02(testCases, allRelativesWithSTno)
 * --------------------------------------------------------
 * This function calculates the minimum total distance from an 
 * optimal location to each relative's house.
 * For each test case, it finds the median house location, 
 * calculates the total distance to it, and outputs the result.
 * ---------------------------------------------------------
*/
void HW3_02(int testCases, const std::vector<std::vector<int>>& allRelativesWithSTno) {
    for (int i = 0; i < testCases; ++i) {
        const std::vector<int>& houses = allRelativesWithSTno[i];

        // Sorting the house positions to find the median
        std::vector<int> sortedHouses = houses;
        std::sort(sortedHouses.begin(), sortedHouses.end());

        // Getting median house position
        int median = sortedHouses[sortedHouses.size() / 2];

        // Calculating the total distance from each house to the median
        int totalDistance = 0;
        for (int house : sortedHouses) {
            totalDistance += std::abs(house - median);
        }

        std::cout << totalDistance << std::endl;
    }
}

/* --------------------------------------------------------
 * Function: flip
 * Usage: flip(stack, pos)
 * --------------------------------------------------------
 * Reverses the order of pancakes from the top to the specified position in the stack.
 * --------------------------------------------------------*/
void flip(std::vector<int>& stack, int pos) {
    std::reverse(stack.begin(), stack.begin() + pos);
}

/* --------------------------------------------------------
 * Function: sortPancakeStack
 * Usage: sortPancakeStack(stack)
 * --------------------------------------------------------
 * This function sorts a given stack of pancakes using a sequence 
 * of "pancake flips" to order the pancakes from smallest (top) 
 * to largest (bottom). It outputs the original stack followed 
 * by the sequence of flips needed to sort the stack.
 * For each test case, the function identifies the largest unsorted 
 * pancake, flips it to the top, and then moves it to its correct 
 * position, repeating this process until the stack is sorted.
 * --------------------------------------------------------
 */

void sortPancakeStack(const std::vector<int>& stack) {
    std::vector<int> pancakes = stack;  
    std::vector<int> flipSequence;     

    int n = pancakes.size();

    for (int p : stack) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    // Sorting process
    for (int size = n; size > 1; --size) {
        // Finding the position of the largest unsorted pancake within the current size
        int maxPos = std::max_element(pancakes.begin(), pancakes.begin() + size) - pancakes.begin();

        if (maxPos + 1 != size) { 
            if (maxPos != 0) {  
                flip(pancakes, maxPos + 1);
                flipSequence.push_back(maxPos + 1);
            }
            flip(pancakes, size);
            flipSequence.push_back(size);
        }
    }

    // printing the flip sequence followed by a 0
    for (int flipPos : flipSequence) {
        std::cout << flipPos << " ";
    }
    std::cout << "0" << std::endl;
}

/* --------------------------------------------------------
 * Function: HW3_03
 * Usage: HW3_03(stacks)
 * --------------------------------------------------------
 * This function processes multiple stacks of pancakes.
 * -------------------------------------------------------*/
void HW3_03(const std::vector<std::vector<int>>& stacks) {
    for (const auto& stack : stacks) {
        sortPancakeStack(stack);
    }
}

/* --------------------------------------------------------
 * Function: HW3_04
 * Usage: HW3_04(testCases)
 * --------------------------------------------------------
 * This function counts the carry operations required to add 
 * pairs of multi-digit numbers in each test case. 
 * For each pair of numbers, it adds digits from right to left, 
 * keeping track of carry operations whenever a sum of two digits 
 * (plus any existing carry) is 10 or greater.
 * After processing each pair, it outputs the number of carry 
 * operations needed or specifies if there were none.
 * --------------------------------------------------------
 */
void HW3_04(const std::vector<std::pair<std::string, std::string>>& testCases) {
    for (const auto& testCase : testCases) {
        const std::string& num1 = testCase.first;
        const std::string& num2 = testCase.second;
        
        // Stopping process if "0 0" is encountered
        if (num1 == "0" && num2 == "0") {
            break;
        }

        int carry = 0, carryCount = 0;
        int len1 = num1.size(), len2 = num2.size();
        int maxLength = std::max(len1, len2);
        
        // Looping from the least significant digit to the most significant
        for (int i = 0; i < maxLength; ++i) {
            int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
            int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
            
            int sum = digit1 + digit2 + carry;
            
            if (sum >= 10) {
                carry = 1;
                ++carryCount;
            } else {
                carry = 0;
            }
        }

        if (carryCount == 0) {
            std::cout << "No carry operation." << std::endl;
        } else if (carryCount == 1) {
            std::cout << "1 carry operation." << std::endl;
        } else {
            std::cout << carryCount << " carry operations." << std::endl;
        }
    }
}


/* --------------------------------------------------------
 * Function: HW3_05
 * Usage: HW3_05(numbers)
 * --------------------------------------------------------
 * This function finds the smallest exponent E for each integer 
 * in the given list "numbers" such that 2^E starts with that 
 * integer's digits as a prefix.
 * For each integer, the function iteratively calculates powers 
 * of 2 and checks if the resulting value's initial digits match 
 * the integer. If a match is found, it outputs the exponent E; 
 * --------------------------------------------------------
 */
void HW3_05(const std::vector<int>& numbers) {
    for (int targetPrefix : numbers) {
        bool matchFound = false;
        int exponent = 1;  // Start with 2^1

        // Converting targetPrefix to a string for easy prefix matching
        std::string prefixString = std::to_string(targetPrefix);

        // Loop until we find a matching exponent or reach a stopping condition
        while (!matchFound) {
            // Calculating the value of 2^exponent
            double powerValue = std::pow(2, exponent);

            std::string powerString = std::to_string(static_cast<long long>(powerValue));

            // Checking if powerString starts with the target prefix
            if (powerString.substr(0, prefixString.size()) == prefixString) {
                std::cout << exponent << std::endl;
                matchFound = true;
            } 
            
            // Stopping if no match found after a large number
            if (exponent > 1000000) {  
                std::cout << "no power of 2" << std::endl;
                break;
            }
            ++exponent;
        }
    }
}
