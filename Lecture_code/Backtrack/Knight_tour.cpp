#include<bits/stdc++.h>
using namespace std;
#define N 8

int board[N][N];

int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int x, int y){
    return (x>=0 && x<N && y>=0 && y<N && board[x][y] == -1);
}

void printSol(){
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            cout << setw(2) << board[x][y] << " ";
        }
        cout << endl;
    }
}

bool Solve(int x, int y, int movei, int xMove[], int yMove[]){
    int k, next_x, next_y;
    if(movei == N*N)   return true;

    for(k=0; k<N; k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(isSafe(next_x, next_y)){
            board[next_x][next_y] = movei;
            if(Solve(next_x, next_y, movei+1, xMove, yMove))    return true;
            else    board[next_x][next_y] = -1;
        }
    }
    return false;
}


int main(){
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            board[x][y] = -1;

    // Bắt đầu từ ô đầu tiên của bàn cờ
    board[0][0] = 0;

    // Bắt đầu từ bước thứ nhất và vị trí 0,0
    if (Solve(0, 0, 1, xMove, yMove) == false) {
        std::cout << "Solution does not exist";
        return false;
    } else
        printSol();

    return true;
    return 0;
}