#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
int alpha[1500] = {};
char arr[500];
int moum = 0;
int jaum = 0;

void print_string(int cur_alpha_position, int cur_arr_position) {
	if (cur_arr_position == L) {
		if (moum < 1 || jaum < 2) return;
		for (int i = 0; i < L; i++) {
			cout << (char)arr[i];
		}
		cout << endl;
		return;
	}
	for (int i = cur_alpha_position; i <= 'z'; i++) {
		if (alpha[i] == 1) {
			arr[cur_arr_position] = (char)i;
			if ((char)i == 'a' || (char)i == 'e' || (char)i == 'i' || (char)i == 'o' || (char)i == 'u') moum += 1;
			else jaum += 1;
			print_string(i + 1, cur_arr_position + 1);
			if ((char)i == 'a' || (char)i == 'e' || (char)i == 'i' || (char)i == 'o' || (char)i == 'u') moum -= 1;
			else jaum -= 1;
		}
	}
	return;
}

int main(void) {
	char tmp;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> tmp;
		alpha[(int)tmp] = 1;
	}

	print_string('a', 0);

	return 0;
}