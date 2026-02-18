// Leetcode 693. Binary Number with Alternating Bits
// problem link : https://leetcode.com/problems/binary-number-with-alternating-bits/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int result = n ^ (n >> 1);
        return (result & (result + 1)) == 0;
    }
};