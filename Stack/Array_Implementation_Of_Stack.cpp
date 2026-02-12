#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int arr[5];
    int idx;

    Stack(){     // constructor
        idx=-1;
    }

    void push(int val){
        if(idx==4){
            cout<<"Stack is full";
            return;
        }
        idx++;
        arr[idx]=val;
    }

    void pop(){
        if(idx==-1){
            cout<<"Stack is Empty";
            return;
        }
        idx--;
    }

    int top(){
        if(idx==-1){
            cout<<"Stack is Empty";
            return -1;
        }
        return arr[idx];
    }

    int size(){
        return idx+1;
    }
};

int main(){
    Stack st;
    cout<<st.top()<<endl;
    st.push(88);
    st.push(44);
    st.push(77);
    st.size();
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
}