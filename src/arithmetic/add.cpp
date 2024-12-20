#include <arithmetic.h>
#include <bits/stdc++.h>

int math::sum(vector<int> &nums){
    return std::accumulate(nums.begin(),nums.end(),0);
}