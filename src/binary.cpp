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