#include <iostream>
#include <algorithm>

using namespace std;

int mx_count = 0;
int R, C;
char mapi[30][30];
int status[500] = {};

void run(int x, int y, int n) {
	if (n > mx_count) mx_count = n;
	if (x < 0 || x >= R || y < 0 || y >= C) return;

	if (status[(int)mapi[x][y]] == 0) {
		status[(int)mapi[x][y]] = 1;
		run(x + 1, y, n + 1);
		run(x - 1, y, n + 1);
		run(x, y + 1, n + 1);
		run(x, y - 1, n + 1);
		status[mapi[x][y]] = 0;
	}
}

int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> mapi[i];
	}
	run(0, 0, 0);
	cout << mx_count << endl;

}