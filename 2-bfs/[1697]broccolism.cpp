#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> Q;
bool LINE[200002] = {};
int SUBIN;
int SUMIN;

int bfs()
{
    Q.push(make_pair(SUBIN, 0));

    int cur_time;
    int cur_pos;
    while (!Q.empty())
    {
        cur_pos = Q.front().first;
        cur_time = Q.front().second;
        Q.pop();

        if (cur_pos == SUMIN) //done!
            return cur_time;
        if (LINE[cur_pos] == true)
            continue;

        LINE[cur_pos] = true;
        if (cur_pos < min(50001, SUMIN) && LINE[cur_pos * 2] != true)
            Q.push(make_pair(cur_pos * 2, cur_time + 1));
        if (cur_pos < SUMIN && LINE[cur_pos + 1] != true)
            Q.push(make_pair(cur_pos + 1, cur_time + 1));
        if (cur_pos > 0 && LINE[cur_pos - 1] != true)
            Q.push(make_pair(cur_pos - 1, cur_time + 1));
    }
}

int main()
{
    cin >> SUBIN >> SUMIN;

    int print_me = bfs();

    cout << print_me << endl;
}