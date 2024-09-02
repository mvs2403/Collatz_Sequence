#include <iostream>
#include <vector>

using namespace std;

// Global variables to track the number that produces the longest Collatz sequence
int max_starting_number = 1;
long long max_length = 1;

// Declare upper_limit variable to store the upper limit for Collatz sequences
int upper_limit;

/**
 * Function to compute the length of the Collatz sequence for a given number 'n'.
 * It uses dynamic programming to store and reuse previously computed lengths in 'dp'.
 *
 * @param n: The starting number for the Collatz sequence.
 * @param dp: A reference to a vector used for dynamic programming to store lengths.
 * @return: The length of the Collatz sequence for the number 'n'.
 */
long long collatz_length(long long n, vector<long long>& dp) {
    long long original = n;  // Store the original value of 'n' to update dp later
    long long length = 0;    // Initialize length of sequence

    // Compute Collatz sequence until it reaches 1
    while (n != 1) {
        // If the current number is within the dp range and its sequence length is already known
        if (n < dp.size() && dp[n] != 0) {
            length += dp[n];  // Use the stored length to avoid recalculating
            break;
        }

        // Apply Collatz sequence rules
        if (n % 2 == 0) {
            n /= 2;  // If 'n' is even, divide by 2
        } else {
            n = 3 * n + 1;  // If 'n' is odd, multiply by 3 and add 1
        }
        length++;  // Increment the length of the sequence
    }

    // Store the computed sequence length in dp if within the range
    if (original < dp.size()) {
        dp[original] = length;
    }

    return length + 1;  // Return the total length, including the starting number
}

/**
 * Function to find the number below 'limit' that produces the longest Collatz sequence.
 *
 * @param limit: The upper limit for starting numbers to consider.
 * @return: The starting number below 'limit' that produces the longest sequence.
 */
int longest_collatz_sequence(int limit) {
    vector<long long> dp(limit*1, 0);  // Initialize dp vector with size 'limit'
    max_starting_number = 1;  // Reset max starting number
    max_length = 1;           // Reset max sequence length

    // Iterate through all starting numbers below 'limit'
    for (int i = 2; i < limit; i++) {
        long long length = collatz_length(i, dp);  // Compute the Collatz sequence length
        // Update max length and starting number if a longer sequence is found
        if (length > max_length) {
            max_length = length;
            max_starting_number = i;
        }
    }

    return max_starting_number;  // Return the number with the longest sequence
}

int main(int argc, char* argv[]) {
    // If an upper limit is provided as a command-line argument, use it; otherwise, prompt the user
    if (argc > 1) {
        upper_limit = std::atoi(argv[1]);
    } else {
        std::cout << "Please enter the upper limit: ";
        std::cin >> upper_limit;
    }

    // Find the number with the longest Collatz sequence below the upper limit
    int result = longest_collatz_sequence(upper_limit);
    cout    << "\n\nMax Key: " << result
            << "\nMax Value: " << max_length
            << "\n\n";

    return 0;  // End of the program
}