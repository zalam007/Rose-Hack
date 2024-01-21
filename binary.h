#pragma once

#include <string>
#include <iostream>

using namespace std;

void PrintMenu();

int binaryToDecimal(const string& binary);
string getBinaryInput();
string decimalToBinary(int decimal);
string removeWhiteSpace(const string& binary);
string binaryToHex(const string& binary);
string hexToBinary(const string& hexadecimal);
