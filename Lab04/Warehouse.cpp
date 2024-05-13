#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, T, D;
    cin >> N >> T >> D;

    vector<int> a(N + 1);  // Mảng lưu số lượng hàng tại mỗi trạm
    vector<int> t(N + 1);  // Mảng lưu thời gian thu gom hàng tại mỗi trạm

    for (int i = 1; i <= N; ++i)
        cin >> a[i];
    for (int i = 1; i <= N; ++i)
        cin >> t[i];

    // Khởi tạo bảng quy hoạch động
    vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));

    // Khởi tạo giá trị cơ bản: kiểm tra nếu chỉ thu gom hàng tại một trạm mà không đi đâu khác
    for (int i = 1; i <= N; ++i) {
        if (t[i] <= T) {
            dp[i][t[i]] = max(dp[i][t[i]], a[i]);
        }
    }

    // Điền giá trị vào bảng quy hoạch động
    for (int i = 1; i <= N; ++i) {
        for (int pt = 1; pt <= T; ++pt) {
            if (dp[i][pt]) { // Nếu tại trạm i đã có thu gom
                for (int j = i + 1; j <= min(N, i + D); ++j) {
                    if (pt + t[j] <= T) {
                        dp[j][pt + t[j]] = max(dp[j][pt + t[j]], dp[i][pt] + a[j]);
                    }
                }
            }
        }
    }

    // Tìm giá trị lớn nhất trong bảng quy hoạch động để đó là kết quả cuối cùng
    int max_goods = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= T; ++j) {
            max_goods = max(max_goods, dp[i][j]);
        }
    }

    cout << max_goods << endl;
    return 0;
}
