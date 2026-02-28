// Leetcode : 11
// Problem link : https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size()-1 , MaxArea = 0;
        while(i<j){
            int Minheight = min(height[i],height[j]);
            int width = j-i;
            int area = Minheight*width;
            MaxArea = max(MaxArea,area);
            if(height[i]>height[j]) j--;
            else i++;
        }
        return MaxArea;
    }
};