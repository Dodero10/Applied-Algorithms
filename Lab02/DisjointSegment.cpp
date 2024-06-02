#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> s;
int n;

bool comp(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        s.push_back(make_pair(a, b));
    }
    
    sort(s.begin(), s.end(), comp);
    
    int result = 0;
    
    int last = -1;
    
    for(int i=0; i<n; i++){
        if(s[i].first > last){
            result++;
            last = s[i].second;
        }
    }
    
    cout << result;
    
    return 0;
}