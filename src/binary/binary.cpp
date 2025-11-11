#include "../include/binary/binary.hpp"
#include "../include/eventHandler/eventHandler.hpp"
#include <cstdint>
#include <iostream>
#include <string>


binary::binary(std::string command, std::string input) // Forward command to corresponding function
{
    if(command == "NumToBin")
    {
        if(!ErrorCheckDecimalInput(input))
        {
            std::cout << eventHandler::ErrorManager(3);
            return;
        } 

        NumToBin(std::stoi(input));
    }

    else if(command == "BinToNum")
    {   
        if(!ErrorCheckBinaryInput(input))
        {
            std::cout << eventHandler::ErrorManager(3);
            return;
        } 
    
        BinToNum(input);
    }

    else
    {
        std::cout << eventHandler::ErrorManager(2); return;
    }
}

binary::~binary(){}

void binary::NumToBin(int64_t num) //Convert decimal value (int) to binary number
{
    std::vector<int> bin;
    int64_t numToBin = num;

    if(numToBin < 0)
        numToBin = numToBin * -1;

    while(numToBin >= 2) 
    {  
        if(numToBin % 2 == 0)
            bin.insert(bin.begin(), 0);

        else
            bin.insert(bin.begin(), 1);
        
        numToBin = numToBin / 2;
    }

    if (numToBin != 0)
        bin.insert(bin.begin(), 1);

    else
        bin.insert(bin.begin(), 0);

    // jälkikäsittely
    bin = HasValidFours(bin);
    PrintBinayVector(bin, num);
}

std::vector<int> binary::HasValidFours(std::vector<int> bin) // Make sure we have valid four number segments by adding zeros
{
    int index = 0;

    for(int i = 0; i < bin.size(); i++)
    {
        if(index == 4)
            index = 0;
        
        index++;
    }

    index = 4 - index;
    
    for(int i = 0; index > i; i++)
    {
        bin.insert(bin.begin(), 0);
    }

    return bin;
}

void binary::PrintBinayVector(std::vector<int> bin, int originalNumber)// Print binary vector by four bit sections 1001 1010 .. .

{
    std::cout << "Number: " << originalNumber << " toBin = ";

    if (originalNumber < 0)
        std::cout << "-";

    int x = 0;

    for(int i = 0; i < bin.size(); i++)
    {
        if(x == 4)
        {
            std::cout << " ";
            x = 0;
        }
        std::cout << bin[i];
        x++;
    } 
}

void binary::BinToNum(std::string binary) // Convert string binary to to decimal
{
    int64_t factor = 1;
    int64_t total = 0;

    for(int value : ConvertStringToIntVector(binary))
    {
        if(value == 1)
        {
            total += factor;
        }
        factor *= 2;
    }
   
    PrintDecimalValue(binary, total);
}

std::vector<int> binary::ConvertStringToIntVector(std::string binary) // Convert string binary to int type vector of bits
{
    std::vector<int> digits;

    for(char character : binary)
    {
        if(isdigit(character))
            digits.insert(digits.begin(), character - '0');
    }

    return digits;
}

void binary::PrintDecimalValue(std::string binary, int64_t decimalValue) // Print decimal values
{
    std::cout << " Your binary value: " ;

    int index = 0;

    for(char c : binary)
    {
        std::cout << c;
        
        if(index == 9)
        {
            std::cout << ".. .";
            break;
        }

        if(c != ' ')
            index++;
    }

    std::cout << " = " << decimalValue << " as decimal value.";
    return;
}

bool binary::ErrorCheckDecimalInput(std::string input)
{
    for(char character : input)
    {
        if(!isdigit(character))
            return false;
    }
    return true;
}

bool binary::ErrorCheckBinaryInput(std::string input)
{
    int count = 0;

    for(char character : input)
    {
        if(character != '1' && character != '0' && character != ' ') 
            return false;
            
        else if(count > 63) 
            return false;

        count++;
    }
    return true;
}
