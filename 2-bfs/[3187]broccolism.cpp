#include <iostream>
#include <queue>
#include <string>

using namespace std;

char **ground;
int R;
int C;
queue<pair<int, int>> Q;
int wolf = 0;
int sheep = 0;

int what_are_you(int i, int j)
{
    int return_me = 0; //empty or fence

    if (ground[i][j] == '#')
        return -1;
    else if (ground[i][j] == 'v')
        return_me = 1; //wolf
    else if (ground[i][j] == 'k')
        return_me = 2; //sheep
    
    ground[i][j] = '#';

    return return_me;
}


void bfs(int row, int col) // (x, y) is the starting position of a wolf or a sheep!!
{
    int num_of_wolf = 0;
    int num_of_sheep = 0;

    Q.push(make_pair(row, col));

    int i, j, what_am_i;
    while (!Q.empty())
    {
        //check
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        
        what_am_i = what_are_you(i, j);
        
        if (what_am_i == -1)
            continue;
        else if (what_am_i == 1)
            num_of_wolf++;
        else if (what_am_i == 2)
            num_of_sheep++;
        
        if (i - 1 > -1 && ground[i - 1][j] != '#') //go up.
            Q.push(make_pair(i - 1, j));
        if (i + 1 < R && ground[i + 1][j] != '#') //go down.
            Q.push(make_pair(i + 1, j));
        if (j - 1 > -1 && ground[i][j - 1] != '#') //go left.
            Q.push(make_pair(i, j - 1));
        if (j + 1 < C && ground[i][j + 1] != '#') //go right.
            Q.push(make_pair(i, j + 1));
        
    }

    if (num_of_sheep > num_of_wolf)
        sheep += num_of_sheep;
    else
        wolf += num_of_wolf;
}

int main()
{
    //get input.
    cin >> R >> C;

    ground = new char *[R];

    string tmp_input = "";
    for (int i = 0; i < R; ++i)
    {
        ground[i] = new char[C];

        cin >> tmp_input;
        for (int j = 0; j < C; ++j)
            ground[i][j] = tmp_input[j];
    }

    //do!
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (ground[i][j] == 'v' || ground[i][j] == 'k')
                bfs(i, j);
    
    cout << sheep << " " << wolf << endl;
}