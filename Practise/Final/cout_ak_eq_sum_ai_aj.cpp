#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countTriplets(int n, vector<int>& a) {
    int count = 0;
    unordered_map<int, int> freq;

    for (int num : a) {
        freq[num]++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int total = a[i] + a[j];
            if (freq.find(total) != freq.end()) {
                count += freq[total];
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = countTriplets(n, a);
    cout << result << endl;

    return 0;
}
