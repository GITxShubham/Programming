// Leetcode : 70
// https://leetcode.com/problems/climbing-stairs/description/


#include<bits/stdc++.h>
using namespace std;

// With the help of memorization

// class Solution {
// public:
//     int helper(int n , vector<int>& dp){
//         if(n==0 || n==1) return 1;
//         if(dp[n] != -1) return dp[n];
//         return dp[n] = helper(n-2 , dp) + helper(n-1 , dp);
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
//         return helper(n,dp);
//     }
// };



// with the help of tabulation method(Bottom-up technique)

// class Solution {
// public:
//     int helper(int n , vector<int>& dp){
//        dp[0] = 1;
//        dp[1] = 1;
//        for(int i = 2 ; i <= n ; i++) dp[i] = dp[i-1] + dp[i-2];
//         return dp[n];
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
//         return helper(n,dp);
//     }
// };




// iterative manner

class Solution {
public:
    int helper(int n , vector<int>& dp){
       int prev = 1 , prev2 = 1;
       for(int i = 2 ; i <= n ; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
       }
        return prev;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};