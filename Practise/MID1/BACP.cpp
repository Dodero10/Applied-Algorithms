// Mô tả bài toán:
// Bài toán BACP là thiết kế một chương trình học cân bằng bằng cách phân bổ các khóa học vào các kỳ sao cho tải học thuật của mỗi kỳ được cân bằng. Có N khóa học 1, 2, …, N phải được phân bổ vào M kỳ 1, 2, …, M. Mỗi khóa học i có số tín chỉ là \(c_i\) và có một số khóa học là điều kiện tiên quyết. Tải của một kỳ được định nghĩa là tổng số tín chỉ của các khóa học được phân vào kỳ đó.

// Thông tin về các điều kiện tiên quyết được biểu diễn bằng một ma trận \(A_{NxN}\) trong đó \(A_{i,j} = 1\) chỉ ra rằng khóa học i phải được phân vào một kỳ trước kỳ mà khóa học j được phân vào. Tính toán giải pháp thỏa mãn các ràng buộc sau:

// - Thỏa mãn các ràng buộc về điều kiện tiên quyết: nếu \(A_{i,j} = 1\), thì khóa học i phải được phân vào một kỳ trước kỳ mà khóa học j được phân vào.
// - Tải tối đa cho tất cả các kỳ là nhỏ nhất.

// Đầu vào:

// - Dòng 1 chứa N và M (2 ≤ N ≤ 16, 2 ≤ M ≤ 5)
// - Dòng 2 chứa \(c_1, c_2, …, c_N\)
// - Dòng i+2 (i = 1,…, N) chứa dòng thứ i của ma trận A

// Đầu ra:

// - Một dòng duy nhất chứa tải tối đa cho tất cả các kỳ của giải pháp tìm được.

// Ví dụ:
// Đầu vào:

// 6 2
// 4 4 4 4 2 4 
// 0 0 0 0 0 0 
// 0 0 0 0 0 0 
// 0 0 0 0 0 0 
// 0 0 1 0 0 0 
// 0 0 1 0 0 0 
// 1 0 0 0 0 0

// Đầu ra:
// 12

#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[20][20];
int minload=INT_MAX;
int c[20];
int peroid[20];
int res[20];
int visited[20];
vector<vector<int>> before(20);
vector<vector<int>> after(20);

bool check(int k, int x){
    for (int a_before: before[k]){
        if (res[a_before]!=0 && res[a_before]>x){
            return false;
        }
    }

    for (int a_after : after[k]){
        if(res[a_after]!=0 && res[a_after]<x){
            return false;
        }
    }
    return true;
}

void TRY(int k){
    for(int i=1; i<=m; i++){
        if(check(k,i)){
            res[k]=i;
            peroid[i]+=c[k];

            if(k==n){
                int max_c=0;
                for(int j=1; j<=m; j++){
                    if(peroid[j]>max_c){
                        max_c=peroid[j];
                    }
                }
                minload=min(minload, max_c);
            }
            else{
                TRY(k+1);
            }
            peroid[i]-=c[k];
        }
    }
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for (int i=1; i<=n; i++){
        cin>>c[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >>A[i][j];
            if (A[i][j]==1){
                before[j].push_back(i);
                after[i].push_back(j);
            }
        }
    }
    TRY(1);
    cout<<minload;
}