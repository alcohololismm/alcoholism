#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<pair<int, int>> Q; //pair<position, num>
bool AVAILABLE[100][100] = {};
int R, C; //goal is (R - 1, C - 1)

int bfs()
{
    Q.push(make_pair(0, 1));

    int cur_tmp, cur_i, cur_j, cur_time;
    while (!Q.empty())
    {
        cur_tmp = Q.front().first;
        cur_time = Q.front().second;
        cur_i = cur_tmp / 100;
        cur_j = cur_tmp % 100;

        Q.pop();

        if (cur_i == R - 1 && cur_j == C - 1) // done!
            return cur_time;
        if (AVAILABLE[cur_i][cur_j] == false) //already visited.
            continue;
        
        AVAILABLE[cur_i][cur_j] = false;
        
        if (cur_i + 1 < R && AVAILABLE[cur_i + 1][cur_j] == true)
            Q.push(make_pair((cur_i + 1) * 100 + cur_j, cur_time + 1));
        if (cur_i - 1 > -1 && AVAILABLE[cur_i -1][cur_j] == true)
            Q.push(make_pair((cur_i - 1) * 100 + cur_j, cur_time + 1));
        if (cur_j + 1 < C && AVAILABLE[cur_i][cur_j + 1] == true)
            Q.push(make_pair(cur_i * 100 + cur_j + 1, cur_time + 1));
        if (cur_j - 1 > -1 && AVAILABLE[cur_i][cur_j - 1] == true)
            Q.push(make_pair(cur_i * 100 + cur_j - 1, cur_time + 1));
    }
}

int main()
{
    //get input.
    cin >> R >> C;

    string tmp_input = "";
    for (int i = 0; i < R; ++i)
    {
        cin >> tmp_input;
        for (int j = 0; j < C; ++j)
        {
            if (tmp_input[j] == '1')
                AVAILABLE[i][j] = true;
            else
                AVAILABLE[i][j] = false;            
        }
    }

    int print_me = bfs();

    cout << print_me << endl;
}