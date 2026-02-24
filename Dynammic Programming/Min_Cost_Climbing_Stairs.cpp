// Leeetcode 746. 
// Link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include<bits/stdc++.h>
using namespace std; 


// class Solution {
// public:
//     int helper(vector<int>& cost , vector<int>& dp , int idx){
//         if(idx >= cost.size()) return 0;
//         if(dp[idx] != -1) return dp[idx];

//         int a = cost[idx] + helper(cost , dp , idx+1);
//         int b = cost[idx] + helper(cost , dp , idx+2);

//         return dp[idx] = min(a,b);
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n,-1);
//         return min(helper(cost , dp , 0) , helper(cost , dp , 1));
//     }
// };



// Method 2

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2) return min(cost[0] , cost[1]);

        for(int i = 2 ; i < n ; i++) cost[i] += min(cost[i-1] , cost[i-2]);

        return min(cost[n-1] , cost[n-2]);
    }
};