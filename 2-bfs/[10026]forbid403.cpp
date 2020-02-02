#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n, ans_, ans_blind;
char map_[101][101];
char map_blind[101][101];
int visited_[101][101];
int visited_blind[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs_(int x, int y) {

    visited_[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x > n-1 || next_y < 0 || next_y > n-1) {
            continue;
        }

        if (map_[next_x][next_y] == map_[x][y] && !visited_[next_x][next_y]) {
            dfs_(next_x, next_y);
        }

    }
}

void dfs_blind(int x, int y) {

    visited_blind[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > n - 1) {
            continue;
        }

        if (map_blind[next_x][next_y] == map_blind[x][y] && !visited_blind[next_x][next_y]) {
            dfs_blind(next_x, next_y);
        }

    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;

            if (temp == 'R')
                map_blind[i][j] = 'G';
            else {
                map_blind[i][j] = temp;
                map_[i][j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited_[i][j]) {
                ans_++;
                dfs_(i, j);
            }
        }
    }

    cout << ans_ << ' ';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited_blind[i][j]) {
                ans_blind++;
                dfs_blind(i, j);
            }
        }
    }

    cout << ans_blind << endl;


    return 0;
}