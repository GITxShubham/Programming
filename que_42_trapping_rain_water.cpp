// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 
#include <iostream>
#include <vector>          
using namespace std;

int trap(vector<int>& height) {
        
       int n = height.size();
       //previous greatest element
       int prev[n];
       prev[0]=-1;
       int max=height[0];
       for(int i=1;i<n;i++){
        prev[i]=max;
        if (height[i]>max)   max=height[i];
       } 
       //next greatest element
       int next[n];
       next[n-1]=-1;
       max=height[n-1];
       for(int i=n-2;i>=0;i--){
next[i]=max;
        if (height[i]>max)   max=height[i];
       }
       //minimum array
       int mini[n];
       for(int i=0;i<n;i++){
        mini[i]=min(prev[i],next[i]);
       }
       //calculating water
       int water = 0;
       for(int i=1;i<n-1;i++){
        if(mini[i]>height[i])   water = water + (mini[i] - height[i]);
       }
       return water;
    }
int main(){
vector<int> height;
height.push_back(4);
height.push_back(2);
height.push_back(0);
height.push_back(3);
height.push_back(2);
height.push_back(5);

int water  = trap(height);
cout<<"water trapped = "<<water;
}