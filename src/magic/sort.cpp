#include <bits/stdc++.h>
#include "magic.h"
using namespace std;

void merge(vector<int> &nums,int low,int mid,int high){
    vector<int>temp;
    int i = low;
    int j = mid+1;
    while(i<=mid&& j<=high){
        if(nums[i]<=nums[j]){
            temp.emplace_back(nums[i]);
            i++;
        }else{
            temp.emplace_back(nums[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.emplace_back(nums[i]);
        i++;
    }
    while(j<=high){
        temp.emplace_back(nums[j]);
            j++;
    }
    for(int k =low; k<=high;k++){
        nums[k] = temp[k-low];
    }
}

void magic::sort(vector<int> &nums,int low,int high){
 if(low<high){
    int mid = low+(high -low)/2;
    sort(nums,low,mid);
    sort(nums,mid+1,high);
    merge(nums,low,mid,high);
 }
}
