// Leetcode 278. 
// Problem Statement: https://leetcode.com/problems/first-bad-version/

#include<bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1 , hi = n;
        int firstOccurence = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isBadVersion(mid)){
                firstOccurence=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return firstOccurence;
    }
};