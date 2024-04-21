#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    stack<char> st;

    for(char c : s){
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
        }
        else{
            if (st.empty()){
                cout << "0";
                return 0;
            }
            else if( (c == ']' && st.top() == '[') ||
                     (c == '}' && st.top() == '{') ||
                     (c == ')' && st.top() == '(')){
                     st.pop();
            }
            else{
                cout << "0";
                return 0;
            }
        }
    }
    
    if(st.empty()){
        cout << "1";
    } else {
        cout << "0";
    }
    
    return 0;
}
