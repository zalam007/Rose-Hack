#include "binary.h"
#include <cmath>

void PrintMenu() {
    cout << "Menu:\n";
    cout << "1. Convert binary to decimal\n";
    cout << "2. Convert decimal to binary\n";
    cout << "3. Convert binary to hexadecimal\n";
    cout << "4. Convert hexadecimal to binary\n";
    cout << "q. Quit\n";
    cout << "Enter your choice: ";
}

// Converts binary number to decimal
int binaryToDecimal(const string& binary) {
    int decimalTotal = 0;
    int power = 0;

    // Start at the right
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            // Calculate power and add to total
            decimalTotal += pow(2, power);
        }
        ++power;
    }

    return decimalTotal;
}

string getBinaryInput() {
    string binaryInput;

    // Get binary input from the user
    cout << "Enter a binary number: ";
    cin >> binaryInput;

    // Validate binary input
    for (char digit : binaryInput) {
        if (digit != '0' && digit != '1') {
            cout << "Invalid binary input. Please enter a binary number.\n";
            exit(1); // Exit with an error code
        }
    }

    return binaryInput;
}

// Converts decimal number to binary
string decimalToBinary(int decimal) {
    // Nothing
    if (decimal == 0) {
        return "0";
    }

    string binary = "";
    while (decimal > 0) {
        // remained is 0 or 1
        int remainder = decimal % 2;
        // add to binary
        binary = to_string(remainder) + binary;
        // divide by 2
        decimal /= 2;
    }

    return binary;
}

string binaryToHex(/*parameter*/);

string hexToBinary(/*parameter*/);