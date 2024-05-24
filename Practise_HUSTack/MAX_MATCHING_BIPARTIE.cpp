#include<bits/stdc++.h>
using namespace std;

const  long long MaxN = 1e5+5;

int n, m;
vector<bool> bVisited[MaxN];
vector<int> aMatch[MaxN];
int res;

void backTrack(int u, int count){
    
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int u;  cin >> u;
        for(int j=1; j<=u; j++){
            int v; cin >> v;
            aMatch[i].push_back(v);
        }
    }

    return 0;
}