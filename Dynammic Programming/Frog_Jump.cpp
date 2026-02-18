// Geeks for Geeks - Frog Jump
// https://practice.geeksforgeeks.org/problems/frog-jump/0

#include<bits/stdc++.h>
using namespace std;

// Method 1: Using DP(memorization)

// class Solution {
//   public:
//     int helper(vector<int>& height , int n , vector<int>& dp){
//         if(n == 0) return 0;
//         if(dp[n] != -1) return dp[n];
//         int left = helper(height , n-1 , dp) + abs(height[n] - height[n-1]);
//         int right = INT_MAX;
//         if(n>1) right = helper(height , n-2 , dp) + abs(height[n] - height[n-2]);
//         return dp[n] = min(left,right);
//     }
//     int minCost(vector<int>& height) {
//         int n = height.size();
//         vector<int> dp(n+1,-1);
//         return helper(height,n-1,dp);
//     }
// };




//  Method 2 : Using tabulation method

// class Solution {
//   public:
//     int minCost(vector<int>& height) {
//         int n = height.size();
//         vector<int> dp(n+1,-1);
//         dp[0] = 0;
//         for(int i = 1 ; i < n ; i++){
//             int left = dp[i-1] + abs(height[i] - height[i-1]);
//             int right = INT_MAX;
//             if(i>1) right = dp[i-2] + abs(height[i] - height[i-2]);
//             dp[i] = min(left,right);
//         }
//         return dp[n-1];
//     }
// };


// Method 3 : Space optimization
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int prev = 0;
        int prev2 = 0;
        for(int i = 1 ; i < n ; i++){
            int left = prev + abs(height[i] - height[i-1]);
            int right = INT_MAX;
            if(i>1) right = prev2 + abs(height[i] - height[i-2]);
            int curr = min(left,right);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};