#include <iostream>

using namespace std;

int board[9][9] = {};
int zeros[81][2] = {}; //gonna store position.
int num_of_zero = 0; //gonna store number of zeros on the board.

bool is_fillable(int x, int y, int put_me)
{
    for (int i = 0; i < 9; ++i) //check vertical & horizontal line.
        if (board[y][i] == put_me || board[i][x] == put_me)
            return false;

    //..and check square.
    int top_left_x = (x / 3) * 3;
    int top_left_y = (y / 3) * 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[top_left_y + i][top_left_x + j] == put_me)
                return false;

    //done!
    return true;
}

void sudoku(int num)
{
    if (num_of_zero <= num) //done!
    {
        //...then, print!
        for (int y = 0; y < 9; ++y)
        {
            for (int x = 0; x < 9; ++x)
                cout << board[y][x] << " ";
            cout << endl;
        }

        exit(0); //NOT "return" .. ..!!
    }
    
    int put_here_x = zeros[num][1];
    int put_here_y = zeros[num][0];

    for (int put = 1; put < 10; ++put)
    {
        if (is_fillable(put_here_x, put_here_y, put))
        {
            board[put_here_y][put_here_x] = put;
            sudoku(num + 1);
            board[put_here_y][put_here_x] = 0;
        }
    }
}

int main()
{
    //get input
    int tmp;
    for (int y = 0; y < 9; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            cin >> tmp;
            board[y][x] = tmp;

            if (tmp == 0)
            {
                zeros[num_of_zero][0] = y;
                zeros[num_of_zero++][1] = x;
            }
        }
    }

    sudoku(0);

}