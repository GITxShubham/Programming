// Leetcode : 1402.
// Problem Link: https://leetcode.com/problems/reducing-dishes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin() , satisfaction.end());
        int suf[n];
        suf[n-1] = satisfaction[n-1];
        for(int i = n-2 ; i >= 0 ; i--) suf[i] = satisfaction[i] + suf[i+1];
        //  FINDING PIVOT INDEX
        int idx = -1;
        for(int i = 0 ; i < n ; i++){
            if(suf[i] >= 0){
                idx = i;
                break;
            }
        }
        if(idx == -1) return 0;
        // MAXIMUM SUM OF LIKE-TIME COEFFICIENT
        int maxsum = 0 , x = 1;
        for(int i = idx ; i < n ; i++){
            maxsum += (satisfaction[i]*x);
            x++;
        }
        return maxsum;
    }
};