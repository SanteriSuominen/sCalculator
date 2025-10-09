#pragma once
#include <iostream>
#include <vector>

class binary {
    public:
        binary();
        ~binary();
        void NumToBin(int);
        void BinToNum(std::string);

    private:
        std::vector<int> HasValidFours(std::vector<int>);
        void PrintBinayVector(std::vector<int>, int);
        void PrintDecimalValue(std::string, long int);
        std::vector<int> ConvertStringToIntVector(std::string);
};  