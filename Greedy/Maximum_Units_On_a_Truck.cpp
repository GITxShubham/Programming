// Leetcode 1710
// https://leetcode.com/problems/maximum-units-on-a-truck/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a , vector<int> &b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int MaxUnits = 0;
        for(int i = 0 ; i < boxTypes.size() ; i++){
            if(boxTypes[i][0] <= truckSize){
                MaxUnits += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                MaxUnits += boxTypes[i][1] * truckSize;
                break;
            }
        }
        return MaxUnits;
    }
};

int main(){
    return 0;
}