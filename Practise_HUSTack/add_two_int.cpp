#include<bits/stdc++.h>
using namespace std;

string a, b;
string res = "";

int main(){
    cin >> a >> b;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while(i>=0 || j>=0 || carry){
        int sum = carry;
        if(i>=0){
            sum += a[i] - '0';
            i--;
        }
        if(j>=0){
            sum += b[j] - '0';
            j--;
        }

        carry = sum / 10;
        res = to_string(sum%10) + res;
    }

    cout << res;
    
    return 0;
}