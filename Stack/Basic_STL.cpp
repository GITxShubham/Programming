#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack <int> st;
    cout<<st.size()<<endl;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;


    // printing in reverse order

    // method 1(emptying stack)

    // while(st.size()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl<<st.size()<<endl;    // size will be now 0 as stack is fully empty


    // Method 2 (using extra space)

    stack <int> temp;
    while(st.size()){
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;

    // putting elements back from temp to st(this step can also be used to 
    // print elements in forward manner)
    while(temp.size()){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl<<st.size()<<endl;   
}