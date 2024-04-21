#include<bits/stdc++.h>
using namespace std;

int n, a[15];
long long S, curMoney;
vector<int> curMoneySet;

void printMoneySet(){
    for(int i : curMoneySet)    cout << i << " ";
    cout << endl;
}

void genMoneySet(){
    int lastIndex = curMoneySet.empty() ? 0 : curMoneySet.back();
    for(int i=lastIndex; i<n; i++){
        if(curMoney + a[i] <= S){
            curMoney += a[i];
            curMoneySet.push_back(a[i]);
            if(curMoney == S)   printMoneySet();
            else    genMoneySet();
            curMoney -= a[i];
        }
    }
}

int main(){
    cin >> n >> S;
    for(int i=0; i<n; i++)  cin >> a[i];
    
    curMoneySet.clear();
    curMoney = 0;
    genMoneySet();

    return 0;
}