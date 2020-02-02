#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string.h>
#define MAX 303
using namespace std;
int n, m, year;
int map_[MAX][MAX];
int map_copy[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void input(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map_[i][j];
        }
    }
}

void bfs(int x, int y){
    queue <pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()){
        int top_x = q.front().first;
        int top_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = top_x + dx[i];
            int next_y = top_y + dy[i];

            if(map_[next_x][next_y] == 0 || visited[next_x][next_y] ||
            next_x >= n|| next_y >=m || next_x < 0 || next_y < 0) continue;

            visited[next_x][next_y] = 1;
            q.push(make_pair(next_x, next_y));

        }
    }
}

int melt(int x, int y){

    int cnt = 0;
    for(int i=0; i<4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(map_[next_x][next_y] == 0) cnt++;
    }

    return cnt;

}
int main() {

    cin >> n >> m;
    input();

    while(true) {

        int landCnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map_[i][j] != 0 && !visited[i][j]) {
                    landCnt++;
                    bfs(i, j);
                }
            }
        }
        
        if (landCnt >= 2) {cout << year << endl; return 0;}
        if (landCnt == 0) {cout << 0 << endl; return 0;}

        //melt
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map_[i][j] != 0) {
                    map_copy[i][j] = map_[i][j] - melt(i, j);
                    if (map_copy[i][j] < 0) map_copy[i][j] = 0;
                }
            }
        }

        year++;

        memcpy(map_, map_copy, sizeof(map_));
        memset(visited, 0, sizeof(visited));
        memset(map_copy, 0, sizeof(map_copy));
    }
}