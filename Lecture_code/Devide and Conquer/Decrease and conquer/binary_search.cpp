#include<bits/stdc++.h>

using namespace std;

bool BinarySearch(vector<int>& A, int low, int high, int x){
    if(low > high) return false;
    int mid = (low + high) / 2;
    if(A[mid] == x) return true;
    if(A[mid] > x) return BinarySearch(A, low, mid -1, x);
    if(A[mid] < x) return BinarySearch(A, mid + 1, high, x);
}

int main(){
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 5;
    cout << BinarySearch(A, 0, A.size() - 1, x) << endl;
    return 0;
}