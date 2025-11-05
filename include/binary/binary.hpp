#pragma once
#include <string>
#include <vector>
#include <cstdint>

class binary {
    public:
        binary(std::string command, std::string value);
        ~binary();

    private:
        void NumToBin(int64_t);
        void BinToNum(std::string);
        std::vector<int> HasValidFours(std::vector<int>);
        void PrintBinayVector(std::vector<int>, int);
        void PrintDecimalValue(std::string, int64_t);
        std::vector<int> ConvertStringToIntVector(std::string);
        bool ErrorCheckBinaryInput(std::string);
        bool ErrorCheckDecimalInput(std::string);
};  