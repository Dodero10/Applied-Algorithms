#include<bits/stdc++.h>
using namespace std;

vector<int> A;
int x;

bool p(int i){
    return A[i] >= x;
}

int main(){

    // cin x and A
    cin >> x;
    int n;
    cin >> n;
    A.resize(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    // binary search
    int low = 0, high = n-1;
    while(low < high){
        int mid = (low+high)/2;
        if(p(mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    if(low==high && p(low)){
        cout << "Min index" << low << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    return 0;
}