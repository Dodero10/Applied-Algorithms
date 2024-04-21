#include<bits/stdc++.h>
using namespace std;

int n;
string curString;

void genString(int pos){
    for(char i='0'; i<='1'; ++i){
        if(curString.size() == n){
            cout << curString << endl;
        }
        else{
            curString.push_back(i);
            genString(pos+1);
            curString.pop_back();
        }
    }
}

int main(){
    cin >> n;
    curString = "";
    genString(1);

    return 0;
}