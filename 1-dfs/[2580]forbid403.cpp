#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;


int checkCol[10][10];
int checkRow[10][10];
int checkSquare[10][10];
int sdoku[10][10];

void print(){

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) {
            cout << sdoku[i][j] << ' ';
        }
        cout << endl;
    }
}

bool canFill(int row, int col, int k){
    if(checkRow[row][k] || checkCol[k][col] || checkSquare[row / 3 * 3 + col / 3][k]) return false;
    return true;
}

void solve(int cnt){

    if(cnt >= 81){
        print();
        exit(0);
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){

            if(sdoku[i][j] == 0){
                for(int k=1; k<10; k++) {

                    if (canFill(i, j, k)) {
                        sdoku[i][j] = k;
                        checkRow[i][k] = 1;
                        checkCol[k][j] = 1;
                        checkSquare[i / 3 * 3 + j / 3][k] = 1;

                        solve(cnt + 1);

                        sdoku[i][j] = 0;
                        checkRow[i][k] = 0;
                        checkCol[k][j] = 0;
                        checkSquare[i / 3 * 3 + j / 3][k] = 0;
                    }
                }
                return;
            }
        }
    }


}
int main(){

    int cnt = 0;

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) {
            cin >> sdoku[i][j];

            int input = sdoku[i][j];
            checkRow[i][input] = 1;
            checkCol[input][j] = 1;
            checkSquare[i / 3 * 3 + j / 3][input] = 1;

            if(input != 0) cnt++;
        }
    }

    solve(cnt);


    return 0;
}