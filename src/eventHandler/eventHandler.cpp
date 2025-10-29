#include "../include/eventHandler/eventHandler.hpp"
#include "../include/binary/binary.hpp"
#include <limits>
#include <iostream>
#include <string>


eventHandler::eventHandler()
{
    ProgramManager();
}

eventHandler::~eventHandler()
{
    
}


void eventHandler::ProgramManager()
{

    std::string input = "";
    std::string command[3] = {""};

    int i = 0;

    InputString(input);

    for(char character : input)
    {
        if(character == '/')
            i++;

        else
            command[i] += character;
    }
    
    std::map<std::string, std::function<void()>> manager;

    manager["binary"] = [command](){binary bin(command[1], command[2]);};

    manager["hexadecimal"] = []() {    std::cout << "Kone käynnistyy...\n"; };
    manager["matrix"] = []() {         std::cout << "Kone käynnistyy...\n"; };
    manager["vectors"] = []() {        std::cout << "Kone käynnistyy...\n"; };
    manager["vectors"] = []() {        std::cout << "Kone käynnistyy...\n"; };

    auto it = manager.find(command[0]);
    if (it != manager.end()) 
     it->second();

    else
        std::cout << "manager doesn't match any known tasks!\n"; 

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