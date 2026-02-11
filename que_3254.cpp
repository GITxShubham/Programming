// You are given an array of integers nums of length n and a positive integer k.

// The power of an array is defined as:

// Its maximum element if all of its elements are consecutive and sorted in ascending order.
// -1 otherwise.
// You need to find the power of all 
// subarrays
//  of nums of size k.

// Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

 

// Example 1:

// Input: nums = [1,2,3,4,3,2,5], k = 3

// Output: [3,4,-1,-1,-1]

// Explanation:

// There are 5 subarrays of nums of size 3:

// [1, 2, 3] with the maximum element 3.
// [2, 3, 4] with the maximum element 4.
// [3, 4, 3] whose elements are not consecutive.
// [4, 3, 2] whose elements are not sorted.
// [3, 2, 5] whose elements are not consecutive.
// Example 2:

// Input: nums = [2,2,2,2,2], k = 4

// Output: [-1,-1]

// Example 3:

// Input: nums = [3,2,3,2,3,2], k = 2

// Output: [-1,3,-1,3,-1]

#include <iostream>
#include <vector> 
using namespace std;
void display(vector <int> &a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
cout<<endl;
}

int main(){
int k;
vector<int>v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4); 
v.push_back(3);
v.push_back(2);
v.push_back(5);
display(v);
cout<<"Enter the size of consecutiveness : ";
cin>>k;
vector<int> res;
        for(int i=0;i<v.size()-k+1;i++){
        int a=0;
    for(int j=0;j<k-1;j++){
      
       if(v[i+j+1]-v[i+j]==1) a++;
    }
    if(a==k-1)
    res.push_back(v[i+k-1]);
    else
    res.push_back(-1);
    a=0;
       }
display(res);       
}