// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 
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
//   NOTE : here 0 represents red   ,   1 represent white    and    2 reprresent blue
vector<int>v;
v.push_back(0);
v.push_back(2);
v.push_back(1);
v.push_back(1); 
v.push_back(0);
v.push_back(2);
v.push_back(2);
v.push_back(2);
v.push_back(0);
display(v);
int noz=0,no1=0,no2=0;
for(int i=0;i<v.size();i++){
if(v[i]==0) noz++;
if(v[i]==1) no1++;
if(v[i]==2) no2++;
}


for(int i=0;i<v.size();i++){
    if(i<noz)   v[i]=0;
   else if(i>=noz&&i<no1+noz) v[i]=1;
    else  v[i]=2;
   }
display(v);
}