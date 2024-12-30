#include  "../tools.hpp"

int magic::sum(std::vector<int> &nums){
    return std::accumulate(nums.begin(),nums.end(),0);
}