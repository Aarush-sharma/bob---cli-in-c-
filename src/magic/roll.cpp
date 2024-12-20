#include "magic.h"
#include<random>

int magic::roll(int size){
    int lower_bound = std::pow(10, size - 1);
    int upper_bound = std::pow(10, size) - 1; 

    std::random_device rd;
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dis(lower_bound, upper_bound);

    return dis(gen);
}