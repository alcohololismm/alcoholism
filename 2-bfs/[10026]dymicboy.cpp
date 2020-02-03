#include <iostream>
#include <algorithm>

using namespace std;

int N;
char mapi[400][400];

bool mark1[400][400] = {};
int mark2[400][400] = {};

int que[400000][2];
int st, ed;
int cur_x, cur_y;
int result1, result2;

void marking1(int x, int y, char target) {
	if (x < 0 || y < 0 || x >= N || y >= N) return;
	if (mark1[x][y] == 1) return;
	if (mapi[x][y] != target) return;
	mark1[x][y] = 1;
	marking1(x + 1, y, target);
	marking1(x - 1, y, target);
	marking1(x, y + 1, target);
	marking1(x, y - 1, target);
}

void marking2(int x, int y, char target) {
	if (x < 0 || y < 0 || x >= N || y >= N) return;
	if (mark2[x][y] == 1) return;
	if (mapi[x][y] != target
		&& !(target == 'R' && mapi[x][y] == 'G')
		&& !(target == 'G' && mapi[x][y] == 'R')
		) return;
	mark2[x][y] = 1;
	marking2(x + 1, y, target);
	marking2(x - 1, y, target);
	marking2(x, y + 1, target);
	marking2(x, y - 1, target);
}


int main(void) {
	cin >> N ;
	for (int i = 0; i < N; i++) {
		cin >> mapi[i];
	}
	result1 = result2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mark1[i][j] == 0) {
				marking1(i, j, mapi[i][j]);
				result1 += 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mark2[i][j] == 0) {
				marking2(i, j, mapi[i][j]);
				result2 += 1;
			}
		}
	}
	cout << result1 << " " << result2 << endl;

	return 0;

}