#include<bits/stdc++.h>
using namespace std;

int T, n, C;
vector<int> x;

bool check(int C, int distance){
    int count = 1;
    int lastDist = x[0];
    for(int i=1; i<n; i++){
        if(x[i] - lastDist >= distance){
            count++;
            lastDist = x[i];
            if(count==C) return true;
        }
    }
    return false;
}

int maxDistance(int C){
    int left = 0;
    int res = -1;
    int right = x.back() - x.front();
    
    while(left<=right){
        int mid = left + (right-left)/2;
        if(check(C, mid)){
            left = mid+1;
            res = mid;
        }else{
            right = mid-1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    
    while(T--){
        cin >> n >> C;
        x.resize(n);
        for(int& a : x){
            cin >> a;
        }
        sort(x.begin(), x.end());
        int res = maxDistance(C);
        cout << res << endl;
    }

    return 0;
}