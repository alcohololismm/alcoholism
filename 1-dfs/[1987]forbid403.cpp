#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char map_[20][20];
int alphabet[100];
int visit[100][100];
int R, C, ans;
void dfs(int x, int y, int val){
    ans = max(ans, val);

    for(int i=0; i<4; i++){


        int nx = dx[i] + x;
        int ny = dy[i] + y;
        int index = map_[nx][ny] - 'A' + 1;
        if(nx >= R || ny >= C || nx < 0 || ny < 0) continue;

        if(!visit[nx][ny] && !alphabet[index]){
            visit[nx][ny] = 1;
            alphabet[index] = 1;
            dfs(nx, ny, val + 1);
            visit[nx][ny] = 0;
            alphabet[index] = 0;
        }
    }


}
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map_[i][j];
        }
    }

    int num = map_[0][0] - 'A' + 1;
    alphabet[num] = 1;
    dfs(0, 0, 1);

    cout << ans << endl;

    return 0;
}