#include<bits/stdc++.h>
using namespace std;

long long mem[1001];
long long res;

long long fib(int n){
    if(n<=2 && n>0) return 1;
    if(mem[n] != -1) return mem[n];
    else{
        long long res = fib(n-1) + fib(n-2);
        mem[n] = res;
        return mem[n];
    }
    return 0;
}


int main(){
    for(int i=1; i<=1000; i++){
        mem[i] = -1;
    }

    cout << fib(50);
    return 0;
}