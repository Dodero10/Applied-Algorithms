#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==1) return 1;
    if(n==2) return 1;
    return fib(n-1) + fib(n-2);
}

string fib_string(int i, int n){
    if(i==1) return "A";
    if(i==2) return "B";
    if(i>fib(n-2))  return fib_string(i-fib(n-2), n-1);
    else return fib_string(i, n-2);
}

int main(){

    return 0;
}