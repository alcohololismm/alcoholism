#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char mapi[200][200];
bool went[200][200] = {};
int que[100000][3];
int st, ed;
int cur_x, cur_y, cur_n;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> mapi[i];
	}
	que[st][0] = 0;
	que[st][1] = 0;
	que[st++][2] = 1;

	while (st != ed) {
		cur_x = que[ed][0];
		cur_y = que[ed][1];
		cur_n = que[ed++][2];
		if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= M 
			|| went[cur_x][cur_y] == 1 || mapi[cur_x][cur_y] == '0') continue;
		went[cur_x][cur_y] = 1;

		if (cur_x == N - 1 && cur_y == M - 1) {
			cout << cur_n << endl;
			return 0;
		}

		que[st][0] = cur_x+1;
		que[st][1] = cur_y;
		que[st++][2] = cur_n + 1;

		que[st][0] = cur_x-1;
		que[st][1] = cur_y;
		que[st++][2] = cur_n + 1;

		que[st][0] = cur_x;
		que[st][1] = cur_y+1;
		que[st++][2] = cur_n + 1;

		que[st][0] = cur_x;
		que[st][1] = cur_y-1;
		que[st++][2] = cur_n + 1;

	}

}