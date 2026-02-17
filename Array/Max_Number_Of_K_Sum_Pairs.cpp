// Leetcode : 1679
// problem link : https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp[k-nums[i]] > 0){
                count++;
                mp[k-nums[i]]--;
            }
            else mp[nums[i]]++;
        }
        return count;
    }
};