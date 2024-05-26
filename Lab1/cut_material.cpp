#include<bits/stdc++.h>
using namespace std;

int H, W, n;
int Rec[20][20] = {0};
vector<pair<int, int>> subRec;

bool isValid(int x, int y, int h, int w){
    if(x+h>H || y+w>W) return false;
    for(int i=x; i<x+h; i++){
        for(int j=y; j<y+w; j++){
            if(Rec[i][j]==1) return false;
        }
    }
    return true;
}

void draw(int x, int y, int h, int w, int val){
    for(int i=x; i<x+h; i++){
        for(int j=y; j<y+w; j++){
            Rec[i][j] = val;
        }
    }
}

int trueFalse(int idx){
    if(idx==n) return 1;
    int h = subRec[idx].first;
    int w = subRec[idx].second;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(isValid(i, j, h, w)){
                draw(i, j, h, w, 1);
                if(trueFalse(idx+1)) return 1;
                draw(i, j, h, w, 0);
            }
            
            if(h!=w && isValid(i, j, w, h)){
                draw(i, j, w, h, 1);
                if(trueFalse(idx+1)) return 1;
                draw(i, j, w, h, 0);
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> H >> W >> n;
    subRec.resize(n);
    for(int i=0; i<n; i++){
        cin >> subRec[i].first >> subRec[i].second;
    }
    
    cout << trueFalse(0);
    
    return 0;
}