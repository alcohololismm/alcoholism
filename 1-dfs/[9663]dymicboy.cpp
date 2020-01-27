#include <iostream>
#include <algorithm>

using namespace std;

int N;
int mapi[20][20];
int result = 0;

void mark_cur(int x, int y, int n) {
	for (int i = 0; i < N; i++) {
		mapi[i][y] += n;
		mapi[x][i] += n;
		if (x + i < N && x + i >= 0 && y + i < N && y + i >= 0)
			mapi[x + i][y + i] += n;
		if (x - i < N && x - i >= 0 && y + i < N && y + i >= 0)
			mapi[x - i][y + i] += n;
		if (x - i < N && x - i >= 0 && y - i < N && y - i >= 0)
			mapi[x - i][y - i] += n;
		if (x + i < N && x + i >= 0 && y - i < N && y - i >= 0)
			mapi[x + i][y - i] += n;
	}
}

void set_queen(int cur) {
	if (cur == N) { result += 1; return; }
	for (int i = 0; i < N; i++) {
		if (mapi[cur][i] == 0) {
			mark_cur(cur, i, -1);
			set_queen(cur + 1);
			mark_cur(cur, i, 1);
		}
	}
}

int main(void) {
	cin >> N;
	set_queen(0);
	cout << result << endl;
}