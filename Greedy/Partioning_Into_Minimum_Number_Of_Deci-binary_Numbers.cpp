// Leetcode 1689: Partitioning Into Minimum Number Of Deci-Binary Numbers
// Problem link : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        char Maxch = *max_element(begin(n) , end(n));
        return Maxch-'0';
    }
};