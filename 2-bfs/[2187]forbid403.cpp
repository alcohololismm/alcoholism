#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, ans;
int map_[101][101];
queue <pair<int, int>> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int check[101][101];
void bfs(){

    while(!q.empty()){

        int top_x = q.front().first;
        int top_y = q.front().second;
        check[top_x][top_y] = 1;
        q.pop();

        for(int i=0; i<4; i++){

            int next_x = dx[i] + top_x;
            int next_y = dy[i] + top_y;

            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m
               || map_[next_x][next_y] == 0 || check[next_x][next_y] == 1) continue;

            check[next_x][next_y] = 1;
            map_[next_x][next_y] = map_[top_x][top_y] + 1;
            q.push(make_pair(next_x, next_y));

        }

    }
}
int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map_[i][j]);
        }
    }

    q.push(make_pair(0, 0));
    check[0][0] = 1;
    bfs();

    cout << map_[n-1][m-1] << endl;
    return 0;
}