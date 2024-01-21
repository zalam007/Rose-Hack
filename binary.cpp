#include "binary.h"
#include <cmath>
#include <unordered_map>

void PrintMenu() {
    cout << "Menu:\n";
    cout << "1. Convert binary to decimal\n";
    cout << "2. Convert decimal to binary\n";
    cout << "3. Convert binary to hexadecimal\n";
    cout << "4. Convert hexadecimal to binary\n";
    cout << "5. Toggle File read\n";
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
    cin.ignore();
    getline(cin, binaryInput);
    binaryInput = removeWhiteSpace(binaryInput);

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

string removeWhiteSpace(const string& binary) {
    string newBinary = "";
    for(unsigned i = 0; i < binary.length(); ++i) {
        if(binary[i] != ' ') {
            newBinary += binary[i];
        }
    }
    return newBinary;
}

string binaryToHex(const string& binary) {
    //list all the characters in hexidecimal that a standard 4 ---- can hold (EX 1111)
    const char arr[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string shrinkBinary = binary;
    string hexidecimal = "";

    if (binary.length() >= 4) {
        string shrinkBinary = removeWhiteSpace(binary);
        while (shrinkBinary.length() >= 4) {
            // Last four binary turned to decimal and then turned to hexadecimal character.
            hexidecimal = arr[binaryToDecimal(shrinkBinary.substr(shrinkBinary.length() - 4))] + hexidecimal;
            // remove the last binary
            shrinkBinary = shrinkBinary.substr(0, shrinkBinary.length() - 4);
        }
        if(shrinkBinary.length() >= 1) {
            hexidecimal = arr[binaryToDecimal(shrinkBinary)] + hexidecimal;
        }
    }
    else if(shrinkBinary.length() >= 1) {
        hexidecimal = arr[binaryToDecimal(shrinkBinary)] + hexidecimal;
    }


    return hexidecimal;
}

string hexToBinary(const string& hex) {
    // Define a map to convert each hexadecimal digit to its binary equivalent
    const unordered_map<char, string> hexToBinaryMap = {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
    };

    string binaryResult = "";

    // Iterate through each character in the hex string
    for (char hexDigit : hex) {
        // Convert the hexadecimal digit to its binary equivalent and append to the result
        binaryResult += hexToBinaryMap.at(toupper(hexDigit));
    }

    return binaryResult;
} 
