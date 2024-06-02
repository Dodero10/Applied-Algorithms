#include<bits/stdc++.h>

using namespace std;

int minimizeDifference(vector<int>& arr, int N) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0); // Tính tổng của toàn bộ dãy số
    int partSum = totalSum / 3; // Giá trị trung bình mong muốn cho mỗi phần
    
    vector<unordered_set<int>> dp(4); // Mảng dp dùng để lưu trữ các tổng có thể đạt được
    dp[0].insert(0);

    // Duyệt qua từng phần tử trong dãy số
    for (int num : arr) {
        for (int k = 3; k >= 1; --k) {
            for (int sum : dp[k-1]) {
                dp[k].insert(sum + num);
            }
        }
    }

    int bestDiff = INT_MAX;

    // Duyệt qua tất cả các tổng có thể đạt được cho phần thứ 3
    for (int sum1 : dp[1]) {
        for (int sum2 : dp[2]) {
            int sum3 = totalSum - sum1 - sum2;
            int maxSum = max({sum1, sum2, sum3});
            int minSum = min({sum1, sum2, sum3});
            bestDiff = min(bestDiff, maxSum - minSum);
        }
    }

    return bestDiff;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = minimizeDifference(arr, N);
    cout << result << endl;

    return 0;
}
