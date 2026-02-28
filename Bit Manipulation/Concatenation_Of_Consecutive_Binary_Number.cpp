// Leetcode 1680
// Problem link : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9+7;
    int concatenatedBinary(int n) {
        long result = 0;
        for(int num = 1 ; num <= n ; num++){
            int digit = log2(num) + 1;
            result = (((result << digit) % M) + num) % M;
        }
        return result;
    }
};