#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if((j-i+1)>r)break;//if it exceeds r no point just break 
                else if((j-i+1)>=l){
                   if(ans==-1 && sum>0){
                    //its first value that we got in range and that is greater than zero
                      ans=sum; 
                   }
                   else if(sum>0){
                     //if it is not first time take minimum
                     ans=min(ans,sum);
                   }
                }
            }
        }
        return ans;
    }
};