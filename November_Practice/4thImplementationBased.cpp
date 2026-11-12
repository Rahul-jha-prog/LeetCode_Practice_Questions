#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return 1;
        int i=0;
        int increasing=1;
        int decreasing=1;
        while(i<n){
            int j=i;
            //increasing
            if(j>0 && nums[j-1]<nums[j]){
                while(j<n && nums[j-1]<nums[j]){
                    j++;
                }
                increasing=max(increasing,j-i+1);
                i=j;
            }
            //decreasing
            else if(j>0 && nums[j-1]>nums[j]){
                 while(j<n && nums[j-1]>nums[j]){
                    j++;
                 }
                 decreasing=max(decreasing,j-i+1);
                 i=j;
            }
            else{
                i++;//when previous element is equal to current element 
            }
        }
        return max(increasing,decreasing);
    }
};