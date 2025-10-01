#pragma once
#include <iostream>
#include <vector>

class binary {
    public:
        binary();
        ~binary();
        void NumToBin(int);
    
    private:
        std::vector<int> HasValidFours(std::vector<int>);
        void PrintBinayVector(std::vector<int>, int);
};