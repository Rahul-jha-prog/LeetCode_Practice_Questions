#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//int findMethod
   vector<vector<int>>memo;
   int findMethod(vector<int>& nums,int start,int target){
    int n=nums.size();
    int j = lower_bound(begin(nums) + start, end(nums), target) - begin(nums);
        if(j < n && nums[j] == target) {
            return j;
        }

        return -1;
   }
    int solve(vector<int>& nums,int incr,int i){
        if(memo[i][incr]!=-1)return memo[i][incr];
       int element=nums[i]+incr;
       int len=1;
      //1st option will be increase +1 then look for other element
        int j=findMethod(nums,i+1,element);
        if(j!=-1){
            len=max(len,1+solve(nums,1,j));
        }
        //2nd option will be increase+1 then look for other element
        j = findMethod(nums, i+1, element+1);
        if(j != -1) {
            len = max(len, 1 + solve(nums,0,j));
        }
        return memo[i][incr]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        int result=1;
        memo.assign(n+1, vector<int>(2, -1));
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
    //in start u have 2 choices either search with the element or search with element+1 and return whatever gives u max
           result=max({solve(nums,1,i),solve(nums,0,i),result});
        }
     return result;
    }
};