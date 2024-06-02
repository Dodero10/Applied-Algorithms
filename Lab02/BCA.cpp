#include<bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> teacher(35);
vector<vector<int>> course(35);
int done[35];
int k;
vector<vector<int>> conflict(35);
int res = INT_MAX;

bool check(int c, int t){
    if(teacher[t].size() + 1 >= res) return false;
    
    for(int sub : teacher[t]){
        for(int cour : conflict[c]){
            if(sub==cour) return false;
        }
    }
    return true;
}

void Try(int c){
    for(int t : course[c]){
        if(check(c, t)){
            done[c] = t;
            teacher[t].push_back(c);
            
            if(c==n){
                int maxC = 0;
                for(int i=0; i<m; i++){
                    int tmp = teacher[i].size();
                    maxC = max(maxC, tmp);
                }
                res = min(res, maxC);
            }else{
                Try(c+1);
            }
            
            teacher[t].pop_back();
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m >> n;
    
    for(int i=0; i<m; i++){
        int numSub = 0;
        cin >> numSub;
        for(int j=0; j<numSub; j++){
            int cour; cin >> cour;
            course[cour].push_back(i);
        }
    }
    
    cin >> k;
    
    for(int i=0; i<k; i++){
        int sub1, sub2;
        cin >> sub1 >> sub2;
        conflict[sub1].push_back(sub2);
        conflict[sub2].push_back(sub1);
    }
    
    Try(1);
    
    if (res == INT_MAX) {
        cout << -1; // Không tìm thấy giải pháp
    } else {
        cout << res; // In ra kết quả
    }
    
    return 0;
}