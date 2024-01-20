#include "binary.h"
#include <iostream>

using namespace std;

int main() {


    // Get binary input from the user
    string binaryInput = getBinaryInput();


    // Convert binary to decimal and display the result
    int decimalResult = binaryToDecimal(binaryInput);
    cout << "Decimal equivalent: " << decimalResult << endl;

    return 0;
}