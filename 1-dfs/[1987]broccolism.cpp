#include <iostream>
#include <string>

using namespace std;

int R;
int C;
int PRINTME = 0;
int ALPHA[500] = {};
char BOARD[20][20] = {};

void run(int i, int j, int len)
{
    if (i <= -1 || i >= R || j <= -1 || j >= C) //cannot go.
        return;

    if (ALPHA[BOARD[i][j]] == 1) //done! (need to go back.)
    {
        if (PRINTME < len)
            PRINTME = len;
        return;
    }
    
    ALPHA[BOARD[i][j]] = 1; //mark.
    
    //and go to next step.
    run(i - 1, j, len + 1); //go reft
    //NOT "++len"
    run(i + 1, j, len + 1); //go right
    run(i, j - 1, len + 1); // go down
    run(i, j + 1, len + 1); // go up
    
    ALPHA[BOARD[i][j]] = 0; //unmark.
}

int main()
{
    //get input and initialize.
    cin >> R >> C;
    //make a board
    string tmp = "";
    for (int i = 0; i < R; ++i)
    {
        cin >> tmp;
        for (int j = 0; j < C; ++j)
            BOARD[i][j] = tmp[j];
    }

    run(0, 0, 0);

    cout << PRINTME << endl;
}