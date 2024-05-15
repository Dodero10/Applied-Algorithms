#include<bits/stdc++.h>
using namespace std;

int main (){
    const long long c = 1000000007;
    unsigned long long a,b;
    cin>>a>>b;
    unsigned long long x = 1, y = a%c;
    while (b > 0) {
        if (b & 1) x = (x*y)%c;
        y = (y*y)%c;
        b = b >> 1;
    }
    cout<<x%c;
}
