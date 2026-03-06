// Leetcode : 1784.
// Problem Link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 0 ; i < s.length()-1 ; i++){
            if(s[i] == '0' && s[i+1] == '1') return false;
        }
        return true;
    }
};