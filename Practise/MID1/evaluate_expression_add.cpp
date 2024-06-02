// Viết chương trình để đánh giá một biểu thức cộng các số nguyên không âm. Biểu thức được cung cấp dưới dạng một chuỗi ký tự. Chương trình cần tính tổng các số trong biểu thức và in ra kết quả. Nếu biểu thức không hợp lệ, in ra "NOT_CORRECT".

// Yêu cầu chi tiết:

// Biểu thức bao gồm các số nguyên không âm và các toán tử cộng (+).
// Không có khoảng trắng hoặc ký tự không hợp lệ trong biểu thức.
// Kết quả cuối cùng của phép tính phải được tính theo modulo 1e9+7.
// Điều kiện:

// Nếu biểu thức bắt đầu hoặc kết thúc bằng toán tử cộng hoặc có ký tự không hợp lệ, thì biểu thức được coi là không hợp lệ.
// Các số có thể lớn, vì vậy hãy tính toán tổng theo modul 1e9+7
// Input:
// 123+456+789

// Output:
// 1368

// Input:
// 12+34+56+

// Output:
// NOT_CORRECT
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    getline(cin, s);
    int x=0;
    int old_x=0;
    int n=s.length();
    if(s[0]<'0' || s[0]>'9'){
        cout<<"NOT_CORRECT"<<"\n";
        return 1;
    }
    
    x=s[0]-'0';
    for(int i=1; i<n; i++){
        char y=s[i];
        if(y>='0'&& y<='9'){
            x=x*10+(y-'0');
            x=x%mod;
        }
        else if(y=='+' && (s[i-1]>='0' && s[i-1]<='9')){
            old_x +=x;
            old_x=old_x%mod;
            x=0;
        }
        else{
            cout<<"NOT_CORRECT"<<"\n";
            return 1;
        }
    }
    old_x += x;
    old_x=old_x%mod;
    if(s[n-1]>='0' && s[n-1]<='9'){
        cout<<old_x;
    }
    else{
        cout<<"NOT_CORRECT"<<"\n";
    }
}