#include "../include/binary/binary.hpp"
#include "../include/eventHandler/eventHandler.hpp"
#include <cstdint>
#include <iostream>
#include <string>

binary::binary(std::string command, std::string value)
{
    if(command == "NumToBin")
    {
        for(char character : value)
        {
            if(!isdigit(character))
            {
                eventHandler::ErrorManager(3);
            }
        }
        NumToBin(std::stoi(value));
    }

    else if(command == "BinToNum")
        BinToNum(value);

    else
        std::cout << ErrorManager(2);
}

binary::~binary(){}

void binary::NumToBin(int64_t num) //Muunnetaan integer binääri lukuun (Vectori siältäen 1 ja 0)
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

std::vector<int> binary::HasValidFours(std::vector<int> bin) //Tarkistetaan että tulostamme 10 järjestelmä luvut tasan neljän pariessa 0011 0110 .. .
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

void binary::PrintBinayVector(std::vector<int> bin, int originalNumber)// tulosta binääri vektori 4 arvon välein 1101 1001 0000 .. .

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

void binary::BinToNum(std::string binary)
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

std::vector<int> binary::ConvertStringToIntVector(std::string binary)
{
    std::vector<int> digits;

    for(char character : binary)
    {
        if(character == '1' || character == '0' || character == ' ')
        {
            if(isdigit(character))
                digits.insert(digits.begin(), character - '0');
        }

        else
        {
            std::cout << "Convertion failed! Given input contained values that are other than 1 or 0";
            return {2};
        }
    }

    if (digits.size() > 63)
    {
        std::cout <<"WARNING Your binary code is larger than 63 bits and is not supported by sCalculator. " << std::endl;  
        return {2};
    }
    return digits;
}

void binary::PrintDecimalValue(std::string binary, int64_t decimalValue)
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