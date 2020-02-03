#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int mapi[400][400];
int tmp_mapi[400][400];

int mark[400][400];
int que[400000][2];
int st, ed;
int cur_x, cur_y;
int year;


int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mapi[i][j];
		}
	}
	year = 0;
	while (1) {
		year++;
		for (int x = 1; x < N - 1; x++) {
			for (int y = 1; y < M - 1; y++) {
				tmp_mapi[x][y] = mapi[x][y];
				if (mapi[x - 1][y] == 0) tmp_mapi[x][y] -= 1;
				if (mapi[x + 1][y] == 0) tmp_mapi[x][y] -= 1;
				if (mapi[x][y - 1] == 0) tmp_mapi[x][y] -= 1;
				if (mapi[x][y + 1] == 0) tmp_mapi[x][y] -= 1;
				if (tmp_mapi[x][y] < 0) tmp_mapi[x][y] = 0;
			}
		}
		cur_x = 0;
		cur_y = 0;
		for (int x = 1; x < N - 1; x++) {
			for (int y = 1; y < M - 1; y++) {
				mapi[x][y] = tmp_mapi[x][y];
				if (mapi[x][y] != 0) {
					cur_x = x;
					cur_y = y;
				}
			}
		}
		if (cur_x == 0 && cur_y == 0) {
			cout << 0 << endl;
			return 0;
		}

		st = 0;
		ed = 0;
		que[st][0] = cur_x;
		que[st++][1] = cur_y;
		while (st != ed) {
			cur_x = que[ed][0];
			cur_y = que[ed++][1];
			if (cur_x < 1 || cur_x >= N - 1 || cur_y < 1 || cur_y >= M - 1 ||
				mapi[cur_x][cur_y] == 0 || mark[cur_x][cur_y] == year) continue;
			mark[cur_x][cur_y] = year;

			que[st][0] = cur_x + 1;
			que[st++][1] = cur_y;

			que[st][0] = cur_x - 1;
			que[st++][1] = cur_y;

			que[st][0] = cur_x;
			que[st++][1] = cur_y + 1;

			que[st][0] = cur_x;
			que[st++][1] = cur_y - 1;
		}

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (mapi[x][y] != 0 && mark[x][y] != year) {
					cout << year << endl;
					return 0;
				}
			}
		}

	}
	cout << 0 << endl;
	return 0;

}