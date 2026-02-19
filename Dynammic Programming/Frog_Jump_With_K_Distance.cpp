// Problem Link: https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int n , vector<int>& dp , int k , vector<int>& heights){
        if(n==0) return 0;
        if(dp[n] != -1)return dp[n];
        int mm = INT_MAX;
        for(int j = 1 ; j <= k ; j++){
            if(n-j >= 0){
                int jump = helper(n-j , dp , k , heights) + abs(heights[n] - heights[n-j]);
                mm = min(mm , jump);
            }
        }
        return dp[n] = mm;
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n,-1);
        return helper(n-1,dp,k,heights);
    }
};
