#include "../include/binary.hpp"

binary::binary(){

}

binary::~binary(){

}

void binary::NumToBin(int num) //Muunnetaan integer binääri lukuun (Vectori siältäen 1 ja 0)
{
    std::vector<int> bin;
    int numToBin = num;

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


std::vector<int> binary::HasValidFours(std::vector<int> bin) //Tarkistetaan että tulostamme 10 järjestelmä luvut tasan neljän pariessa 1111 0110 .. .
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

    std::cout << std::endl;
}

void binary::BinToNum(std::string binary)
{
    long int factor = 1;
    long int total = 0;

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

void binary::PrintDecimalValue(std::string binary, long int decimalValue)
{
    std::cout << "Your binary value: " ;

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