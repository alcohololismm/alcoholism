#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string.h>
#define MAX 303
using namespace std;
int r, c, sheep, wolf;
int ansSheep, ansWolf;
char fence[MAX][MAX];
int visit[MAX][MAX];
queue <pair<int, int>> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void bfs(int x, int y){

    q.push(make_pair(x, y));
    visit[x][y] = 1;
    if(fence[x][y] == 'k') sheep++;
    if(fence[x][y] == 'v') wolf++;

    while(!q.empty()){
        int top_x = q.front().first;
        int top_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = top_x + dx[i];
            int next_y = top_y + dy[i];

            if(visit[next_x][next_y] || next_x < 0 || next_y < 0 || next_x >= r || next_y >= c || fence[next_x][next_y] == '#')
                continue;

            if(fence[next_x][next_y] == 'k') sheep++;
            if(fence[next_x][next_y] == 'v') wolf++;

            visit[next_x][next_y] = 1;
            q.push(make_pair(next_x, next_y));
        }
    }
}
void input(){

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> fence[i][j];
        }
    }
}
void solve(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(fence[i][j] != '#' && !visit[i][j]){
                wolf = 0; sheep = 0;
                bfs(i, j);

                if (wolf < sheep)
                    ansSheep += sheep;
                else
                    ansWolf += wolf;
            }
        }
    }
}
int main() {

    cin >> r >> c;

    input();

    solve();

    cout << ansSheep << ' ' << ansWolf << endl;

    return 0;

}