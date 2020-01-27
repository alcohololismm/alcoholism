#include <iostream>

using namespace std;

int num;
int printMe;

bool confirm(bool **square, int row, int col)
{
    //check the vertical constraint
    for (int i = 0; i < row; ++i)
    {
        if (square[i][col] == 1)
        {
            return false;
        }
    }
    
    int check_right = col + 1; 
    int check_left = col - 1; 
    
    for (int i = row - 1; i >= 0; --i)
    {
        //check '/' diag
        if (check_right < num && square[i][check_right] == 1)
            return false;
        else
            check_right++;
            
        //check '\' diag
        if (check_left > -1 && square[i][check_left] == 1)
            return false;
        else
            check_left--;
    }
    
    return true;
}


/*gonna deal with the first -> second -> third -> ... -> last row.*/
void queens(bool **square, int cur_row)
{
    if (cur_row == num) //done!
    {
        printMe++;
        return;
    }
    
    for (int i = 0; i < num; ++i)
    {
        bool tmp = square[cur_row][i];
        
        if (confirm(square, cur_row, i))
        {
            square[cur_row][i] = 1;
            
            queens(square, cur_row + 1);
        }
        
        square[cur_row][i] = tmp;
        //사실 성공할 경우를 생각해서 이전 상태로(tmp 사용) 복구했지만
        //tmp 없애고 square[cur_row][i] = 0; 으로 해도 잘 됨!
        //생각해보니 성공 시에는 여기까지 올 일이 없겠구만
    }
}

int main()
{
    cin >> num;
    
    bool **square = new bool *[num];
    for (int i = 0; i < num; i++)
    {
        square[i] = new bool[num];
        for (int j = 0; j < num; j++)
            square[i][j] = 0;
    }
    queens(square, 0);
    
    cout << printMe << endl;
}