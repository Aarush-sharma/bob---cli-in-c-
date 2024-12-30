#include  "../tools.hpp"

int magic::mul(std::vector<int> &nums){
    int mul = 1;
    for (int num : nums){
        mul *=num;
    }
    return mul;
}