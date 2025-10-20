#pragma once
#include <string>
#include <cstdint>

class eventHandler{
    public:
        eventHandler();
        ~eventHandler();
    private:
        std::string input = " ";
        std::string segmentIdentifier = "sCalculator: ";

        void PrintLogo();
        void ProgramManager();
        std::string InputString(std::string &input);
        bool InputInt(int64_t &input);
        void clearConsole();
};