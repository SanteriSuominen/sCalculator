#include <iostream>
#include <string>

void Header();

int main()
{
   Header();
}

void Header()
{
    std::string statusBar = "calc";
    std::string input = "";
    std::cout << "Welcome to sCalculator! \n\n This is no default calulator, it is meant for more complex calculations \n And predetirmend operations." << std::endl;
    std::cout << "Type (help) for additional information" << std::endl;

    while(true)
    {
        std::cout << statusBar + ": ";
        std::cin >> input;
        statusBar = statusBar + "/" + input;
    }


}