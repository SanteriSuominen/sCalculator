#include "../include/eventHandler/eventHandler.hpp"
#include "../include/binary/binary.hpp"
#include <limits>
#include <iostream>
#include <regex>
#include <string>


eventHandler::eventHandler() // start the program
{
    ProgramManager();
}

eventHandler::~eventHandler()
{
    
}


void eventHandler::ProgramManager()
{
    while(true)
    {                               
        std::string input = "";     // Input gets seperated to 3 part command type/command/value
        std::string command[3] = {""};
        int i = 0;

        std::cout << "\n\n" << segmentIdentifier;

        InputString(input);
        
        if(input == "exit") // Exit if exit
            return;

        for(char character : input) // Original input is segmented as 3 strings that form a list
        {                           // The values represent type, commmand, value
            if(character == '/')
                i++;

            else
                command[i] += character;
        }
        
        std::map<std::string, std::function<void()>> manager; // Map to handle type and give tasks forward to each type

        manager["binary"]       = [command](){binary bin(command[1], command[2]);};
        manager["hexadecimal"]  = [command]() {std::cout << std::stoi(command[2],nullptr, 16);};
        manager["matrix"]       = []() {std::cout << "TBD\n"; };
        manager["vectors"]      = []() {std::cout << "TBD\n"; };
        manager["clear"]        = [this]() { this->ClearConsole(); };
        manager["help"]         = [this]() { this->Help();};

        auto it = manager.find(command[0]);

        if (it != manager.end()) 
            it->second();

        else
            std::cout << ErrorManager(1);
    }
}

std::string eventHandler::InputString(std::string &input) // Handle string input
{
    std::getline(std::cin, input);
    return input;
}

bool eventHandler::InputInt(int64_t &input) // Handle int input
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

void eventHandler::ClearConsole() // duh
{
    std::cout << "\033[2J\033[H" << std::flush;
}

std::string eventHandler::ErrorManager(int code) // Return error string by int code
{
    switch(code)
    { 
        case 1:
            return "\nERROR: Unknown type given! -> type <-/command/value";

         case 2:
            return "\nERROR: Unknown command given! type/-> command <-/value";

         case 3:
            return "\nERROR: Given value dosen't match type or command! type/command/-> value <-";

         case 4:
            return "\nERROR: Your binary code is larger than 63 bits and is not supported by sCalculator.";
        default:
            return "";
    }
}

void eventHandler::Help()
{
    std::cout << "\nHelp:\n\n";
    std::cout << "Task format is: type/command/value | exp: binary/NumToBin/255 Press Enter\n\n";
    std::cout << "Tasks:\n";
    std::cout << "\n-binary      | type: binary | commands: NumToBin & BinToNum |\n"; 
    std::cout << "  1.NumToBin value exp: whole numbers like 1234\n"; 
    std::cout << "  2.BinToNum value exp: 10011010.. . or 1001 1010.. .\n"; 
    std::cout << "\n-hexadecimal | TBD\n";
    std::cout << "\n-matrix      | TBD\n";
    std::cout << "\n-vector      | TBD\n";
    std::cout << "\n-clear       | clear screen\n";
    std::cout << "\n-help        | open help window\n";
}