#include <iostream>
#include <unordered_map>
using namespace std;

// Global Variables
int upper_limit;
unordered_map<int, int> collatz_dict;
unordered_map<int, int> temp_dict;
int current_iteration;
int length;
int seq_length;
int max_key = -1;
int max_value = -1;

// Function to calculate the Collatz sequence length for a given starting number
int calc_collatz(int start_number){
    length = 1;
    int og_num = start_number;

    while (start_number != 1) {
        if (collatz_dict.find(start_number) != collatz_dict.end()){ // If already calculated, use stored value
            return (length + collatz_dict[start_number]);
        } else {  // Otherwise, calculate the next number in the sequence
            temp_dict.insert({start_number, (length+1)});
            if (start_number % 2 == 0) {
                start_number = start_number / 2;
            } else {
                start_number = (start_number * 3) + 1;
            }
            length++;
        }
    }

    // Store computed lengths for intermediate values
    for (auto itr = temp_dict.begin();  itr != temp_dict.end(); itr++) {
        collatz_dict.insert({itr->first, (length - itr->second + 1)});
    }
    temp_dict.clear();

    collatz_dict[og_num] = length;
    return length;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        upper_limit = std::atoi(argv[1]);
    } else {
        std::cout << "Please enter the upper limit: ";
        std::cin >> upper_limit;
    }

    current_iteration = upper_limit;

    // Calculate Collatz sequence length for each number up to the upper limit
    while (current_iteration > 1){
        seq_length = calc_collatz(current_iteration);

        // Track maximum length and corresponding starting number
        if (seq_length > max_value) {
            max_key = current_iteration;
            max_value = seq_length;
        }

        current_iteration--;
    }

    cout << "\n\nMax Key: " << max_key
         << "\nMax Value: " << max_value
         << "\n\n";

    return 0;
}