#include<bits/stdc++.h>
using namespace std;

int n, m;
string curString;
int mask[100] = {0};

void genCombination(int pos){
    if(pos>m){
        cout << curString << endl;
    }
    else{
        for(int i=1; i<=n; i++){
            if(!mask[i]){
                mask[i] = 1;
                curString.push_back('0'+i);
                genCombination(pos+1);
                mask[i] = 0;
                curString.pop_back();
            }
        }
    }
}

int main(){
    cin >> n >> m;
    curString = "";
    genCombination(1);

    return 0;
}