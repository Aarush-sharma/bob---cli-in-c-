#include <arithmetic.h>
#include <vector>

int math::mul(vector<int> &nums){
    int mul = 1;
    for (int num : nums){
        mul *=num;
    }
    return mul;
}