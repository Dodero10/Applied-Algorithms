#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;

    stack<char> st;

    for(char c : s){
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
        }
        else{
            if (st.empty()){
                cout << "0";
                break;
            }
            else if( (c == ']' && st.top() == '[') ||
                     (c == '}' && st.top() == '{') ||
                     (c == ')' && st.top() == '(')){
                     st.pop();
            }
            else{
                cout << "0";
                break;
            }
        }
    }
    return 0;
}