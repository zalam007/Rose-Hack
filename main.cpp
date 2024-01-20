#include "binary.h"
#include <iostream>

using namespace std;
int main() {

    string binaryInput;

    // Get binary input from the user
    cout << "Enter a binary number: ";
    cin >> binaryInput;

    // Validate binary input
    for (char digit : binaryInput) {
        if (digit != '0' && digit != '1') {
            cerr << "Invalid binary input. Please enter a binary number.\n";
            return 1; // Exit with an error code
        }
    }

    // Convert binary to decimal and display the result
    int decimalResult = binaryToDecimal(binaryInput);
    cout << "Decimal equivalent: " << decimalResult << endl;


    return 0;
}