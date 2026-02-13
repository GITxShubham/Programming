#include<iostream>
#include<stack>
#include<string>
using namespace std;

int solve(int a , int b , char y){
    if(y=='+') return a+b;
    else if(y=='-') return a-b;
    else if(y=='*') return a*b;
    else return a/b;
}

int main(){
    string str = "79+4*8/3-";
    stack <int> val;
    for(int i=0 ; i<str.length() ; i++){
        if(str[i]>=48 && str[i]<=57) val.push(str[i]-48);   //str[i] is digit
        else{
            char ch = str[i];
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = solve(val1,val2,ch);
            val.push(ans);
        }
    }
    cout<<val.top();
}