#include<bits/stdc++.h>
using namespace std;

int n;
// mảng đánh dấu cột, đường chéo phụ, đường chéo chính
bool isInCol[13], isInDiag1[25], isInDiag2[25];

//gọi 2 tập riêng chỉ hàng và cột
// tập X có thể bỏ qua do các quân Hậu được sinh ra theo từng hàng
vector<int> curQueenX, curQueenY;

void printQueen(){
    for(int i=0; i<n; i++){
        cout << "(" << curQueenX[i] << ", " << curQueenY[i] << ") ";
        if(i<n-1) cout << ", ";
    }
    cout << endl;
}

void genQueenSet(int curRow){
    for(int curCol = 1; curCol <= n; curCol++){
        int curDiag1 = curRow + curCol;
        int curDiag2 = curRow - curCol + 13;

        if(isInCol[curCol] || isInDiag1[curDiag1] || isInDiag2[curDiag2]) continue;

        curQueenX.push_back(curRow);
        curQueenY.push_back(curCol);
        isInCol[curCol] = true;
        isInDiag1[curDiag1] = true;
        isInDiag2[curDiag2] = true;

        if(curRow == n) printQueen();
        else genQueenSet(curRow+1);

        curQueenX.pop_back();
        curQueenY.pop_back();
        isInCol[curCol] = false;
        isInDiag1[curDiag1] = false;
        isInDiag2[curDiag2] = false;
    }

}

int main(){
    cin >> n;

    memset(isInCol, 0, sizeof(isInCol));
    memset(isInDiag1, 0, sizeof(isInDiag1));
    memset(isInDiag2, 0, sizeof(isInDiag2));

    genQueenSet(1);

    return 0;
}