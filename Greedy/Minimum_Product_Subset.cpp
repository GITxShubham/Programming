#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int MinProduct(vector<int>& arr){
    // We will count number of zero , negative and positive numbers
    int nz = 0 , nn = 0 , np = 0 , MaxNegative = INT16_MIN , ProductOfPositive = 1 , ProductOfNegative = 1;
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i]==0) nz++;
        else if(arr[i] < 0){
            nn++;
            ProductOfNegative *= arr[i];
            MaxNegative = max(MaxNegative , arr[i]);
        }
        else{   // arr[i] > 0  (i.e element is positive)
            np++;
            ProductOfPositive *= arr[i];
        }
    }
    if(nn==0){
        if(nz > 0) return 0;
        else{
            auto it = min_element(arr.begin() , arr.end());
            return *it;
        }
    }
    else{
        if(nn % 2 == 0){        // even number of negative elements
            return (ProductOfNegative / MaxNegative) * ProductOfPositive;
        }
        else{
            return ProductOfPositive * ProductOfNegative;
        }
    }

}

int main(){
    vector<int> arr {-2 , -3 , 1 , 4 , -2};
    cout<<MinProduct(arr);
}