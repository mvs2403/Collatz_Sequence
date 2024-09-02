#include <iostream>
using namespace std;

int upper_limit = 1e5;  // Default upper limit

int main(int argc, char* argv[]) {
    // Get upper limit from command line or user input
    if (argc > 1) {
        upper_limit = std::atoi(argv[1]);
    } else {
        std::cout << "Please enter the upper limit: ";
        std::cin >> upper_limit;
    }

    int max_key = 0;
    int max_value = 0;
    int length;
    int iterator;

    // Iterate through all numbers from upper limit down to 2
    while (upper_limit > 1) {
        length = 1;
        iterator = upper_limit;

        // Calculate Collatz sequence length for current number
        while (iterator != 1) {
            if (iterator % 2 == 0) {
                iterator = iterator / 2;
            } else {
                iterator = (iterator * 3) + 1;
            }
            length++;
        }

        // Check if the current sequence length is the longest
        if (length > max_value) {
            max_key = upper_limit;
            max_value = length;
        }

        upper_limit--;
    }

    cout << "\n\nMax Key: " << max_key
         << "\nMax Value: " << max_value
         << "\n\n";

    return 0;
}