#pragma once
#include <string>
#include <vector>
#include <cstdint>


class binary {
    public:
        binary(std::string command, std::string value);
        ~binary();
        void NumToBin(int64_t);
        void BinToNum(std::string);

    private:
        std::vector<int> HasValidFours(std::vector<int>);
        void PrintBinayVector(std::vector<int>, int);
        void PrintDecimalValue(std::string, int64_t);
        std::vector<int> ConvertStringToIntVector(std::string);
};  