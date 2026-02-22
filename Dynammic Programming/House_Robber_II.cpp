// Leetcode 213. 
// Problem Statement: https://leetcode.com/problems/house-robber-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums , vector<int>& dp , int n){
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = nums[n] + helper(nums,dp,n-2);
        int notpick = 0 + helper(nums,dp,n-1);
        return dp[n] = max(pick,notpick);
    }
    int solve(vector<int>& temp){
        int n = temp.size();
        vector<int> dp(n,-1);
        return helper(temp,dp,n-1);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        // remove first house
        vector<int> temp1(nums.begin()+1,nums.end());

       // Remove last house
        vector<int> temp2(nums.begin() , nums.end()-1);

        return max(solve(temp1) , solve(temp2));
    }
};



