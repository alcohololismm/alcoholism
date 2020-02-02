#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

char picture[100][100];
bool normal[100][100];
bool week[100][100];
int len;
int normal_num = 0;
int week_num = 0;

void normal_bfs(int i, int j)
{
    char color = picture[i][j];

    queue<pair<int, int>> norm;
    
    norm.push(make_pair(i, j));

    int row, col;
    while (!norm.empty())
    {
        row = norm.front().first;
        col = norm.front().second;
        norm.pop();

        if (normal[row][col])
            continue;

        normal[row][col] = true;
    
        if (row + 1 < len && picture[row + 1][col] == color)
            norm.push(make_pair(row + 1, col));
        if (row - 1 > -1 && picture[row - 1][col] == color)
            norm.push(make_pair(row - 1, col));
        if (col + 1 < len && picture[row][col + 1] == color)
            norm.push(make_pair(row, col + 1));
        if (col - 1 > -1 && picture[row][col - 1] == color)
            norm.push(make_pair(row, col - 1));
    }

    normal_num++;
}

void week_bfs(int i, int j)
{
    char color = picture[i][j];

    queue<pair<int, int>> we;

    we.push(make_pair(i, j));

    int row, col;
    while (!we.empty())
    {
        row = we.front().first;
        col = we.front().second;
        we.pop();

        if (week[row][col])
            continue;

        week[row][col] = true;
    
        if (color != 'B')
        {
            if (row + 1 < len && picture[row + 1][col] != 'B')
                we.push(make_pair(row + 1, col));
            if (row - 1 > -1 && picture[row - 1][col] != 'B')
                we.push(make_pair(row - 1, col));
            if (col + 1 < len && picture[row][col + 1] != 'B')
                we.push(make_pair(row, col + 1));
            if (col - 1 > -1 && picture[row][col - 1] != 'B')
                we.push(make_pair(row, col - 1));
        }
        else
        {
            if (row + 1 < len && picture[row + 1][col] == color)
                we.push(make_pair(row + 1, col));
            if (row - 1 > -1 && picture[row - 1][col] == color)
                we.push(make_pair(row - 1, col));
            if (col + 1 < len && picture[row][col + 1] == color)
                we.push(make_pair(row, col + 1));
            if (col - 1 > -1 && picture[row][col - 1] == color)
                we.push(make_pair(row, col - 1));            
        }
    }

    week_num++;
}


int main()
{
    //get input
    cin >> len;

    string tmp_input = "";
    for (int i = 0; i < len; ++i)
    {
        cin >> tmp_input;
        for (int j = 0; j < len; ++j)
            picture[i][j] = tmp_input[j];
    }
    

    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
        {
            if (!normal[i][j])
                normal_bfs(i, j);
            if (!week[i][j])
                week_bfs(i, j);
        }   

    cout << normal_num << " " << week_num << endl;
}