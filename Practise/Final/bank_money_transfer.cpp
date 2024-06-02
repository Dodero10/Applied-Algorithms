#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

void backtrack(const vector<int>& bags, int index, int sum1, int sum2, int& min_diff) {
    if (index == bags.size()) {
        int current_diff = abs(sum1 - sum2);
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
        return;
    }

    backtrack(bags, index + 1, sum1 + bags[index], sum2, min_diff);
    backtrack(bags, index + 1, sum1, sum2 + bags[index], min_diff);
}

int minDifference(const vector<int>& bags) {
    int min_diff = INT_MAX;
    backtrack(bags, 0, 0, 0, min_diff);
    return min_diff;
}

int main() {
    int n;
    cin >> n;
    vector<int> bags(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> bags[i];
    }
    
    cout << minDifference(bags) << endl;
    return 0;
}
