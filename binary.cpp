#include "binary.h"
#include <cmath>
using namespace std;

int binaryToDecimal(const string& binary) {
    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        ++power;
    }

    return decimal;
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
