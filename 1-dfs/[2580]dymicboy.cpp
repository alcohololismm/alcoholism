#include <iostream>
#include <algorithm>

using namespace std;

int mapi[20][20];
int non_valid_num[20][20][20] = { 0 };
int zero_num = 0;
int zeros[100][5];
int result = 0;


void mark(int x, int y, int num, int tmp) {
	for (int i = 0; i < 9; i++) {
		non_valid_num[x][i][num] += tmp;
		non_valid_num[i][y][num] += tmp;
	}
	x = (x / 3) * 3;
	y = (y / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			non_valid_num[x + i][y + j][num] += tmp;
		}
	}
}

void fill_zeros(int cur) {
	if (cur >= zero_num) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << mapi[i][j] << " ";
			}
			cout << endl;
		}
		result = 1;
	}

	if (result == 1) return;

	int cur_x = zeros[cur][0];
	int cur_y = zeros[cur][1];

	for (int i = 1; i <= 9; i++) {
		if (non_valid_num[cur_x][cur_y][i] == 0) {
			mapi[cur_x][cur_y] = i;
			mark(cur_x, cur_y, i, -1);
			fill_zeros(cur + 1);
			mark(cur_x, cur_y, i, 1);
		}
	}
}

int main(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mapi[i][j];
			if (mapi[i][j] == 0) {
				zeros[zero_num][0] = i;
				zeros[zero_num][1] = j;
				zero_num += 1;
			}
			else mark(i, j, mapi[i][j], -1);
		}
	}
	fill_zeros(0);
}