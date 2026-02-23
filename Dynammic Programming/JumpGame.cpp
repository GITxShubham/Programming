// Leetcode : 55
// Problem link : https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>
using namespace std;

// Method 1(Reccursion + Memorization)

// class Solution {
// public:
//     bool helper(vector<int>& nums , int n , int idx , vector<int>& dp){
//         if(idx == n-1) return true;
//         if(dp[idx] != -1) return dp[idx];
//         for(int i = 1 ; i <= nums[idx] ; i++){
//             if(helper(nums , n , idx+i , dp) == true) return dp[idx] = 1;
//         }
//         return dp[idx] = 0;
//     }
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return helper(nums , n , 0 , dp);
//     }
// };


//  Bottom - up Approch

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> v(n,false);

//         v[0] = true;

//         for(int i = 1 ; i < n ; i++){
//             for(int j = i-1 ; j>=0 ; j--){
//                 if(v[j] == true  &&  j+nums[j] >= i){
//                     v[i] = true;
//                     break;
//                 }
//             }
//         }
        
//         return v[n-1];
//     }
// };



// Space optimization   O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachable = 0;

        for(int i = 0 ; i < n ; i++){
            if(i > maxReachable) return false;

            maxReachable = max(maxReachable , i+nums[i]);
        }
        return true;
    }
};