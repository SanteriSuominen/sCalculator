#pragma once
#include <string>
#include <cstdint>
#include <map>
#include <functional>

class eventHandler{
    public:
        eventHandler();
        ~eventHandler();
    private:
        std::string input = " ";
        std::string segmentIdentifier = "sCalculator: ";

        void ProgramManager();
        std::string InputString(std::string &input);
        bool InputInt(int64_t &input);
        void clearConsole();
};