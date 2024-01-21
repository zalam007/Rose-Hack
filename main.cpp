#include "binary.h"

#include <iostream>
#include <fstream>

using namespace std;


int main() {
    // The user inputs commands to navigate the menu
    string command;
    string fileName;
    ifstream inputFile;
    bool toggleReadFile = false;

    //Menu
    while (true) 
    {
        // Print menu options
        PrintMenu();
        if (!(cin >> command) || command == "q") break; // If input fails or user chooses to quit

        if (command == "1")    //Binary to Decimal
        {
            if(toggleReadFile) { // read binary from a file
                cout << "Reading from file..." << endl;
                string binaryFile;
                int decimalResult;
                while(getline(inputFile, binaryFile)) {
                    decimalResult = binaryToDecimal(removeWhiteSpace(binaryFile));
                    cout << "Decimal equivalent: " << decimalResult << "\n" << endl;
                }
            }
            // Get binary input from the user
            else{
                string binaryInput = getBinaryInput();

                // Convert binary to decimal and display the result
                int decimalResult = binaryToDecimal(binaryInput);
                cout << "Decimal equivalent: " << decimalResult << "\n" << endl;
            }
        }
        else if (command == "2")    // Decimal to Binary
        {
            if(toggleReadFile) { // read decimal from a file
                cout << "Reading from file..." << endl;
                int decimalInput;
                while(inputFile >> decimalInput) {
                    string binaryResult = decimalToBinary(decimalInput);
                    cout << "Binary equivalent: " << binaryResult << "\n" << endl;
                }
            }
            else { // Get decimal input from the user
                int decimalInput;
                cout << "Enter a decimal number: ";
                cin >> decimalInput;

                // Convert decimal to binary and display the result
                string binaryResult = decimalToBinary(decimalInput);
                cout << "Binary equivalent: " << binaryResult << "\n" << endl;
            }
        }
        else if(command =="3")    //Binary to hex
        {
            if(toggleReadFile) { // read binary from a file
                cout << "Reading from file..." << endl;
                string binaryFile;
                while(getline(inputFile, binaryFile)) {
                    cout << binaryToHex(binaryFile) << endl;
                }
            }
            
            else{ // Get binary input from the user
                string binaryInput = getBinaryInput();
                cout << binaryToHex(binaryInput) << endl;
            }
        }
        else if(command == "4")    //Hex to binary
        {
            //hex to binary
            if(toggleReadFile) { // read binary from a file
                cout << "Reading from file..." << endl;
                string hexFile;
                while(getline(inputFile, hexFile)) {
                    cout << hexToBinary(hexFile) << endl;
                }
            }
            
            else{ // Get hexadecimal input from the user
                string hexadecimal;
                cin >> hexadecimal;
                cout << hexToBinary(hexadecimal);
            }
        }
        else if(command == "5") {    //Toggle read file
            if(toggleReadFile) {
                toggleReadFile = false;
                cout << "Read file toggle is now off." << endl;
                inputFile.close();
            }
            else {
                toggleReadFile = true;
                cout << "Read file toggle is now on." << endl;
                cout << "Enter file name: " << endl;

                cin.ignore();
                getline(cin, fileName);
                inputFile.open(fileName);

                if(!inputFile.is_open()) {
                    cout << "Error opening " << fileName << endl;
                    return 1;
                }
                else {
                    cout << "File " << fileName << " opened." << endl;
                }
            }
            
        }
        else if(command == "q")    //Quit
        {
            break;
        }
        else{
            cout << "Invalid input. Try again." << endl;
        }
    }

    //in case the file is still open but we are done with the program.
    if(inputFile.is_open()) {
        inputFile.close();
    }

    return 0;
}
