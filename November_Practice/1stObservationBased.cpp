#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long  TotalMoves(vector<int>& nums,int target){
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=abs(nums[i]-target);
        }
        return cnt;
    }
    int minMoves2(vector<int>& nums) {
    //so the logic or simple observation is try to make all element or what can we do is we can sort the array and try to make 
    //all element equal to middle element and to calculate we can use abs() value 
     sort(nums.begin(),nums.end());
     int n=nums.size();
     if(n%2!=0 || n<=2){
        //odd length
        return TotalMoves(nums,nums[n/2]);
     }
     int cnt=min(TotalMoves(nums,nums[n/2+1]),TotalMoves(nums,nums[n/2]));
     return cnt;
    }
};