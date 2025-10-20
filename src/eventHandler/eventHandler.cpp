#include "../include/eventHandler/eventHandler.hpp"
#include "../include/binary/binary.hpp"
#include <limits>
#include <iostream>
#include <string>


eventHandler::eventHandler()
{
    PrintLogo();
    ProgramManager();
}

eventHandler::~eventHandler()
{
    
}

void eventHandler::PrintLogo()
{
    std::cout << "            /$$$$$$            /$$                     /$$             /$$                        "        << std::endl;
    std::cout << "           /$$__  $$          | $$                    | $$            | $$                        "        << std::endl;
    std::cout << "  /$$$$$$$| $$  \\__/  /$$$$$$ | $$  /$$$$$$$ /$$   /$$| $$  /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ "       << std::endl;
    std::cout << " /$$_____/| $$       |____  $$| $$ /$$_____/| $$  | $$| $$ |____  $$|_  $$_/   /$$__  $$ /$$__  $$"        << std::endl;
    std::cout << "|  $$$$$$ | $$        /$$$$$$$| $$| $$      | $$  | $$| $$  /$$$$$$$  | $$    | $$  \\ $$| $$  \\__/"      << std::endl;
    std::cout << " \\____  $$| $$    $$ /$$__  $$| $$| $$      | $$  | $$| $$ /$$__  $$  | $$ /$$| $$  | $$| $$      "       << std::endl;
    std::cout << " /$$$$$$$/|  $$$$$$/|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$      "        << std::endl;
    std::cout << "|_______/  \\______/  \\_______/|__/ \\_______/ \\______/ |__/ \\_______/   \\___/   \\______/ |__/      " << std::endl;
    std::cout << "\n\n";
}

void eventHandler::ProgramManager()
{
    while(true)
    {
        std::cout << "Welcome to sCalculator! Start by selecting from following: \n" << std::endl;

        std::cout << "- binary"         << std::endl;
        std::cout << "- hexadecimal"    << std::endl;
        std::cout << "- matrix"         << std::endl;
        std::cout << "- vectors"        << std::endl;
        std::cout << "- help"           << std::endl;

        std::cout << segmentIdentifier;
        input = InputString(input);
        
        if(input == "binary")
        {
            clearConsole();
            std::cout << "sCalculator/binary: ";
            input = InputString(input);
            clearConsole();

            if(input == "numtobin")
            {
                std::cout << "sCalculator/binary/NumToBin: ";
                int64_t num = 0;

                if(InputInt(num))
                    binary NTB(num);

                 std::cin.get();
                 std::cin.get();
            }

            else if(input == "bintonum")
            {
                std::cout << "sCalculator/binay/BinToNum: ";

                binary BTN(InputString(input));
                std::cin.get();
            }

            else
                continue;

            clearConsole();
        }

        else
            clearConsole();
    }
}

std::string eventHandler::InputString(std::string &input)
{
    std::getline(std::cin, input);
    return input;
}

bool eventHandler::InputInt(int64_t &input)
{ 
    if(!(std::cin >> input))
    {
        std::cout << "\n\nERROR False input was given and can't run current task and will return!\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

void eventHandler::clearConsole() 
{
    std::cout << "\033[2J\033[H" << std::flush;
}