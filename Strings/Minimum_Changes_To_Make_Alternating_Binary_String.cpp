// Leetcode 1758. 
// Problem Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int start_With_0 = 0;
        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0){
                if(s[i] == '1') start_With_0++;
            }
            else{
                if(s[i] == '0') start_With_0++;
            }
        }
        int start_With_1 = n - start_With_0;
        return min(start_With_0 , start_With_1);
    }
};