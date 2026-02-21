// GFG Problem Link: https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents/0

#include<bits/stdc++.h>
using namespace std;

// Method 1: Using Memorization 
 
// class Solution {
//   public:
//     int helper(vector<int>& arr,int n , vector<int>& dp){
//         if(n==0) return arr[0];
//         if(n<0) return 0;
//         if(dp[n] != -1) return dp[n];
//         int pick = arr[n] + helper(arr,n-2,dp);
//         int notpick = 0 + helper(arr,n-1,dp);
//         return dp[n] = max(pick,notpick);
//     }
//     int findMaxSum(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> dp(n,-1);
//         return helper(arr,n-1,dp);
//     }
// };




// Method 2 : Using Tabulation Method
// class Solution {
//   public:
//     int findMaxSum(vector<int>& arr) {
//         code here
//         int n = arr.size();
//         vector<int> dp(n,-1);
//         dp[0] = arr[0];
//         for(int i = 1 ; i < n ; i++){
//             int pick = arr[i] + dp[i-2];
//             int notpick = 0 + dp[i-1];
//             dp[i] = max(pick,notpick);
//         }
//         return dp[n-1];
//     }
// };




// Method 3 : using space optimization
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        int prev = arr[0];
        int prev2 = 0;
        for(int i = 1 ; i < n ; i++){
            int pick = arr[i] + prev2;
            int notpick = 0 + prev;
            int curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};