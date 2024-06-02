// Viết chương trình mô phỏng hoạt động của một priority queue (hàng đợi ưu tiên) với các thao tác sau:

// PUSH x: Thêm một phần tử x vào priority queue.
// POP: Lấy và in ra phần tử có độ ưu tiên cao nhất từ priority queue, sau đó loại bỏ phần tử này khỏi queue.
// Chi tiết:

// Sử dụng một priority queue với độ ưu tiên cao nhất là các giá trị nhỏ nhất (min-heap).
// Chương trình sẽ nhận các lệnh thông qua input từ người dùng cho đến khi gặp ký tự # thì kết thúc.
// Các lệnh có thể là:
// "PUSH x": Thêm giá trị x vào priority queue.
// "POP": Lấy giá trị nhỏ nhất từ priority queue, in ra giá trị này và loại bỏ nó khỏi queue.

// Input:
// PUSH 3
// PUSH 1
// PUSH 2
// POP
// POP
// #

// Output:
// 1
// 2

#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
string s;
int n;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    
    while(1){
        cin >> s;
        if(s=="#")  break;
        if(s=="PUSH"){
            cin >> n;
            q.push(n);
        }
        if(s=="POP"){
            cout << q.top() << endl;
            q.pop();
        }
    }
    
    return 0;
}