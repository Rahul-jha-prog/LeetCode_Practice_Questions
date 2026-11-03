#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
  //Return the minimum total number of moves required so that all elements in nums become equal.
  //logic is simple pick the largest element and cnt the total moves we required to make all the element equal to that element 
    int n=nums.size();
    int max_element=INT_MIN;
    int Total_moves=0;
    for(int i=0;i<n;i++){
        max_element=max(max_element,nums[i]);
    }
    for(int i=0;i<n;i++){
     Total_moves+=max_element-nums[i];
    }
  return Total_moves;
    }
};