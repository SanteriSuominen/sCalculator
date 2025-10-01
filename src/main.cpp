#include <iostream>
#include <string>
#include "../include/binary.hpp"

void Header();

int main()
{
    int num = 0;
    binary obj; 
    while(true)
    {   std::cout << "give num: ";
        std::cin >> num;
        obj.NumToBin(num);
    }
   return 0;
}

void Header()
{
    std::string statusBar = "calc";
    std::string input = "";
    
    std::cout << "Welcome to sCalculator! \n\n This is no default calulator, it is meant for more complex calculations \n And predetermined operations." << std::endl;
    std::cout << "Type (help) for additional information" << std::endl;

    while(true)
    {
        std::cout << statusBar + ": ";
        std::cin >> input;
        statusBar = statusBar + "/" + input;
    }
}
