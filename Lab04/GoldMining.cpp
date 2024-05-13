#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, L1, L2;
    cin >> n >> L1 >> L2;  // Nhập số lượng kho, và khoảng cách tối thiểu và tối đa giữa các kho được chọn
    vector<int> a(n+1), dp(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];  // Nhập lượng vàng tại mỗi kho
    }

    deque<int> window;  // Sử dụng deque để lưu trữ các chỉ số mà tại đó dp[j] là tối đa
    for (int i = 1; i <= n; ++i) {
        dp[i] = a[i];  // Giả định ban đầu là chỉ lấy vàng ở kho hiện tại

        if (!window.empty() && window.front() < i - L2) {
            window.pop_front();  // Xóa các chỉ số không còn trong phạm vi L2
        }

        if (i - L1 >= 0) {
            while (!window.empty() && dp[window.back()] <= dp[i - L1]) {
                window.pop_back();  // Duy trì thứ tự giảm dần của các giá trị dp
            }
            window.push_back(i - L1);  // Thêm chỉ số mới vào cuối hàng đợi
        }

        if (!window.empty()) {
            dp[i] = max(dp[i], dp[window.front()] + a[i]);  // Cập nhật dp[i] nếu cộng dồn vàng từ kho j có dp cao nhất
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result = max(result, dp[i]);  // Kết quả cuối cùng có thể là bất kỳ dp[i] nào, không nhất thiết là dp[n]
    }

    cout << result << endl;  // In ra kết quả

    return 0;
}
