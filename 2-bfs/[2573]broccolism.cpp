#include <iostream>
#include <queue>

using namespace std;

int R, C;
int SEA[300][300];
int TMP_SEA[300][300];
bool BEEN[300][300];
/**
 * returns true if the iceberg is broken, false if not
 * using queue.
 */
bool is_broken()
{
    queue<pair<int, int>> Q;
    int num_of_iceberg = 0;
    bool return_me = false;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (SEA[i][j] != 0 && BEEN[i][j] != true)
            {
                if (num_of_iceberg > 0)
                    return true;

                Q.push(make_pair(i, j));

                int cur_row, cur_col;
                while (!Q.empty())
                {
                    cur_row = Q.front().first;
                    cur_col = Q.front().second;
                    Q.pop();

                    if (BEEN[cur_row][cur_col] == true)
                        continue;
                    
                    BEEN[cur_row][cur_col] = true;

                    if (cur_row + 1 < R && SEA[cur_row + 1][cur_col] != 0)
                        Q.push(make_pair(cur_row + 1, cur_col));
                    if (cur_row - 1 > -1 && SEA[cur_row - 1][cur_col] != 0)
                        Q.push(make_pair(cur_row - 1, cur_col));
                    if (cur_col + 1 < C && SEA[cur_row][cur_col + 1] != 0)
                        Q.push(make_pair(cur_row, cur_col + 1));
                    if (cur_col - 1 > -1 && SEA[cur_row][cur_col - 1] != 0)
                        Q.push(make_pair(cur_row, cur_col - 1)); 
                }

                ++num_of_iceberg;
            }
        }
    }
    
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            BEEN[i][j] = false;

    return false;
}

void melting(int i, int j)
{
    int origin = SEA[i][j];
    int how_much = 0;

    if (i - 1 > -1 && SEA[i - 1][j] == 0)
        ++how_much;
    if (i + 1 < R && SEA[i + 1][j] == 0)
        ++how_much;
    if (j - 1 > -1 && SEA[i][j - 1] == 0)
        ++how_much;
    if (j + 1 < C && SEA[i][j + 1] == 0)
        ++how_much;
    
    if (origin - how_much < 0)
        how_much = origin;
    
    TMP_SEA[i][j] = origin - how_much;
}

bool all_melted()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (SEA[i][j] != 0)
                return false;
    
    return true;
}

int main()
{
    //get input
    cin >> R >> C;

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> SEA[i][j];
            TMP_SEA[i][j] = SEA[i][j];
        }

    int year = 0;
    bool done = false;
    while(!done)
    {
        ++year;

        if (all_melted())
        {
            year = 0;
            break;
        }

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (SEA[i][j] != 0)
                    melting(i, j);
                    
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                SEA[i][j] = TMP_SEA[i][j];
        
        done = is_broken();
    }

    cout << year << endl;
}