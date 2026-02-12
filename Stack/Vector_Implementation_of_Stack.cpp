#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Vector{
    public:
    vector <int> v;
    
    void push(int val){
        v.push_back(val);
    }

    void pop(){
        if(v.size()==0){
            cout<<"Stack is empty";
            return;
        }
        v.pop_back();
    }

    int top(){
        if(v.size()==0){
            cout<<"Stack is empty";
            return -1;
        }
        return v[v.size()-1];
    }

    int size(){
        return v.size();
    }
};

int main(){
    Vector st;
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