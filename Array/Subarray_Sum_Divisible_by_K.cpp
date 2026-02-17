// Leetcode 974
// problem Link : https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0 , result = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(auto x : nums){
            sum += x;
            int rem = ((sum % k) + k) % k;
            if(mp.find(rem) != mp.end()) result += mp[rem];
            mp[rem]++;
        }
        return result;
    }
};