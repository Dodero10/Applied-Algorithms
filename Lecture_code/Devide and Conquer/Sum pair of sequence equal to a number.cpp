#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000];
int M;

int countHalf(int i, int mid, int j) {
    int count = 0;
    int left = i;
    int right = j;
    while (left <= mid && right > mid) {
        int sum = a[left] + a[right];
        if (sum < M) {
            left++;  
        } else if (sum > M) {
            right--; 
        } else {
            count++; 
            left++;
            right--;
        }
    }
    return count;
}

int count(int i, int j) {
    if (i >= j) return 0;
    int mid = (i + j) / 2;
    
    int countLeft = count(i, mid);
    int countRight = count(mid + 1, j);
    int countH = countHalf(i, mid, j);
    return countH + countLeft + countRight;
}

int main() {

    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n >> M;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n); 
    int res = count(0, n - 1);
    cout << res << endl;
    
    return 0;
}
