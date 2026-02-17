// Leetcode : 217
// problem Link : https://leetcode.com/problems/contains-duplicate/description/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums) mp[x]++;
        for(auto x : nums) if(mp[x] > 1) return true;
        return false;
    }
};
