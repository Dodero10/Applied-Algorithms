#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> curVector;
int mask[100] = {0};

void printRes(){
    for (int i : curVector) cout << i << " ";
    cout << endl;
}

void genVec(int pos){
    if(pos>m)   printRes();
    else{
        int start = curVector.empty() ? 1 : curVector.back() + 1;
        for(int i=start; i<=n; i++){
            if(!mask[i]){
                mask[i] = 1;
                curVector.push_back(i);
                genVec(pos+1);
                mask[i] = 0;
                curVector.pop_back();
            }
        }
    }
}

int main(){
    cin >> n >> m;

    curVector.clear();
    genVec(1);

    return 0;
}