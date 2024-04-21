#include<bits/stdc++.h>
using namespace std;

int n, a[15];
long long S, curMoney = 0;
vector<int> curMoneySet;

void printMoneySet(){
    for(int i : curMoneySet)    cout << i << " ";
    cout << endl;
}

void genMoneySet(int idx){
    
    if(curMoney + a[idx] <= S){
        curMoneySet.push_back(a[idx]);
        curMoney += a[idx];
        if(curMoney == S) printMoneySet();
        else genMoneySet(idx);
        curMoney -= a[idx];
        curMoneySet.pop_back();
    }
    else    genMoneySet(idx+1);

}

int main(){
    cin >> n >> S;
    for(int i=0; i< n; i++){
        cin >> a[i];
    }
    curMoneySet.clear();
    genMoneySet(0);
    return 0;
}