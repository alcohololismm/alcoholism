#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
char mapi[300][300];
bool mark[300][300];
int v, k;
int res_v, res_k;

void marking(int x, int y) {
	if (x < 0 || x >= R || y < 0 || y >= C) return;
	if (mapi[x][y] == '#'||mark[x][y] == 1) return;
	mark[x][y] = 1;
	if (mapi[x][y] == 'v') v += 1;
	if (mapi[x][y] == 'k') k += 1;

	marking(x + 1, y);
	marking(x-1, y);
	marking(x, y+1);
	marking(x, y-1);
}


int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> mapi[i];
	}
	res_v = res_k = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			v = 0;
			k = 0;
			marking(i, j);
			if (k > v) res_k += k;
			else res_v += v;
		}
	}

	cout << res_k << " " << res_v << endl;


	return 0;

}