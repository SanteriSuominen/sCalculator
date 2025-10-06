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
            return;
        }
    }

    if (digits.size() > 31 && digits.size < 64)
    {
        std::cout << "WARNING the binary input you provided is larger than 32 bits and will result to extremely large decimal value:" << std::endl;
        std::cout << "Do you wish to continue using 64 bit format allowing possibility of larger decimal values: (Y/n)";
        
        if(std::cin = Y)
        {
             long int factor = 1;
             long int total = 0;

            for(int value : digits)
            {
                if(value == 1)
                {
                    total += factor;
                }
                factor *= 2;
            }
        }
    }

    else
    {

        // tee eri integer koille omat aliohjelmat

    }
    int factor = 1;
    int total = 0;

    for(int value : digits)
    {
        if(value == 1)
        {
            total += factor;
        }
        factor *= 2;
    }

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

    std::cout << " = " << total << " as decimal value.";    
}
