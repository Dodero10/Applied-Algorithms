#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính độ dài dãy con palindrome dài nhất
int longestPalindromicSubsequence(const vector<int>& arr) {
    int N = arr.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Mỗi phần tử đơn lẻ là một palindrome độ dài 1
    for (int i = 0; i < N; ++i) {
        dp[i][i] = 1;
    }

    // Xây dựng bảng dp theo khoảng cách giữa các phần tử
    for (int len = 2; len <= N; ++len) {
        for (int i = 0; i <= N - len; ++i) {
            int j = i + len - 1;
            if (arr[i] == arr[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][N - 1];
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int lpsLength = longestPalindromicSubsequence(arr);
    int minRemovals = N - lpsLength;

    cout << minRemovals << endl;

    return 0;
}
