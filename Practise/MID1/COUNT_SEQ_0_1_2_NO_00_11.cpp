// Viết chương trình để đếm số lượng các dãy ký tự chỉ gồm các số 0, 1 và 2 có độ dài n mà không có hai ký tự liên tiếp nào giống nhau. Kết quả cần được tính theo modulo 1e9+7.
// Yêu cầu chi tiết:

// Đầu vào là một số nguyên n (1 ≤ n ≤ 1000), đại diện cho độ dài của dãy ký tự.
// Kết quả là số lượng dãy ký tự thỏa mãn điều kiện trên.
// Điều kiện:

// Dãy ký tự chỉ gồm các số 0, 1 và 2.
// Không có hai ký tự liên tiếp nào giống nhau (không có "00" hoặc "11").
// 
// Input:
// 3

// Output:
// 12

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int last_0[1005];
int last_1[1005];
int last_2[1005];

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    last_0[1] = last_1[1]= last_2[1]=1;
    int n;
    cin >>n;
    for (int i=2; i<=n; i++){
        last_0[i]=(last_1[i-1]+last_2[i-1])%mod;
        last_1[i]=(last_0[i-1]+last_2[i-1])%mod;
        last_2[i]=((last_1[i-1]+last_2[i-1])%mod+last_0[i-1])%mod;
    }

    cout<<((last_0[n]+last_1[n])%mod+last_2[n])%mod;
}