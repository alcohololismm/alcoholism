#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int que[10000000][2];
int mapi[200010] = {};
int st, ed;
int cur_posi, cur_n;


int main(void) {
	cin >> N >> K;
	st = 0;
	ed = 0;
	que[st][0] = N;
	que[st++][1] = 0;
	while (st != ed) {
		cur_posi = que[ed][0];
		cur_n = que[ed++][1];
		if (cur_posi < 0 || cur_posi>=200000 || mapi[cur_posi] == 1) continue;
		mapi[cur_posi] = 1;
		if (cur_posi == K) {
			cout << cur_n << endl;
			return 0;
		}
		que[st][0] = cur_posi * 2;
		que[st++][1] = cur_n + 1;
		que[st][0] = cur_posi + 1;
		que[st++][1] = cur_n + 1;
		que[st][0] = cur_posi - 1;
		que[st++][1] = cur_n + 1;
	}
	cout << "what the fuck" << endl;
	cout << st << endl;
	return 0;

}