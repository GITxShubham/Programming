// Leetcode 45
// Problem Statement : https://leetcode.com/problems/jump-game-ii/

#include<bits/stdc++.h>
using namespace std;

// Using Recursion + Memorization

class Solution {
public:
    int helper(vector<int>& nums , vector<int>& dp , int idx , int n){
        if(idx >= n-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int count = INT_MAX;
        for(int i = 1 ; i <= nums[idx] ; i++){
            
           if(idx + i < n){
            int a = helper(nums , dp , i+idx , n);
            if(a != INT_MAX) count = min(count , a+1);
           }
            
        }
        return dp[idx] = count;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums , dp , 0 , n);
    }
};