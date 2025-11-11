#pragma once
#include <string>
#include <cstdint>
#include <map>
#include <functional>

class eventHandler{
    public:
        eventHandler();
        ~eventHandler();
        static std::string ErrorManager(int); // Returns strings that mach given error code
    private:
        std::string input = "";
        const std::string segmentIdentifier = "sCalculator: "; // to print at start

        void ProgramManager();                      // Backbone of the program                      
        std::string InputString(std::string &input);// Handle string inputs
        bool InputInt(int64_t &input);              // Handle int inputs
        void ClearConsole();                        // Clean console
        void Help();                          // HELP!!
};