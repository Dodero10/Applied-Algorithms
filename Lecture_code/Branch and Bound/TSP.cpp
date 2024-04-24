#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int n, c[MAX+1][MAX+1];
int c_min = INT_MAX;
int best = INT_MAX;
int curr = 0;
int mark[MAX+1];
int x[MAX+1];

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if(i != j && c[i][j] < c_min)
                c_min = c[i][j];
        }
    }
}

bool check(int i) {
    return !mark[i];
}

void Try(int k) {
    for(int i = 2; i <= n; i++) {
        if(check(i)) {
            x[k] = i;
            mark[i] = 1;
            curr += c[x[k-1]][i];
            if(k == n) {
                if(curr + c[i][1] < best)
                    best = curr + c[i][1];
            } else {
                if(curr + (n-k+1) * c_min < best)
                    Try(k+1);
            }
            curr -= c[x[k-1]][i];
            mark[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    mark[1] = 1;
    x[1] = 1;

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    Try(2);
    cout << best << endl;
    return 0;
}
