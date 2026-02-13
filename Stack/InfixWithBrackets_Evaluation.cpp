#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char x){
    if(x=='+' || x=='-') return 1;
    else return 2;                  // x = * or /
}

int solve(int a , int b , char y){
    if(y=='+') return a+b;
    else if(y=='-') return a-b;
    else if(y=='*') return a*b;
    else return a/b;
}

int main(){
    string str = "(7+9)*4/8-3";   // infix expression
    // we will need two stacks , 1 for values and 1 for operators
    stack <int> val;
    stack <char> op;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i]>=48 && str[i]<=57) val.push(str[i]-48);   //str[i] is digit
        else{                 // s[i] is one of these -> *,+,/,-
            if(op.size()==0) op.push(str[i]);
            else if(str[i]=='(') op.push(str[i]);
            else if(op.top()=='(') op.push(str[i]);
            else if(str[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();   // opening bracket ko bhi uda diya
            }
            else if(priority(str[i])>priority(op.top())) op.push(str[i]);
            else{             // priority(str[i])<=priority(op.top())
                while(op.size()>0 && priority(str[i])<=priority(op.top())){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(str[i]);
            }
        }
    }

    //  the operator stack can still have values , so make it empty
    while(op.size()>0){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top();
}