#include <iostream>
#include <algorithm>
int n, ans;
int chess[16][16];
using namespace std;
bool check(int row, int col){

    //세로
    for(int i=0; i<row; i++){
        if(chess[i][col] == 1) return false;
    }

    //대각선

    int check_right = col + 1;
    int check_left = col - 1;

    for (int i = row - 1; i >= 0; --i)
    {
        //check '/' diag
        if (check_right < n && chess[i][check_right] == 1)
            return false;
        else
            check_right++;

        //check '\' diag
        if (check_left > -1 && chess[i][check_left] == 1)
            return false;
        else
            check_left--;
    }

    return true;
}
void solve(int row){

    if(row == n){
        ans++;
        return;
    }

    for(int i=0; i<n; i++){
        if(check(row, i)){
            chess[row][i] = 1;
            solve(row+1);
            chess[row][i] = 0;
        }
    }

}
int main(){

    cin >> n;

    solve(0);

    //경우의 수 출력
    cout << ans << endl;

    return 0;
}