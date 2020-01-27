// Example program
#include <iostream>
#include <string>

using namespace std;

//i don't know why this is "DFS"... well.. anyway!

int one_two_three(int goal, int now, int ending)
{
    if (ending >= 11)
        return 0;
    if (now == goal) //found
        return 1; //count
    else if (now > goal)
        return 0;
    else //now < goal
    {
        int returnMe = 0;
        
        //we need to add 1, 2, and 3
        for (int i = 1; i < 4; ++i)
        {
            returnMe += one_two_three(goal, now + i, ending + 1);            
        }
        
        return returnMe;
    }
}

int main()
{
    int num;
    cin >> num;
    
    int goal;
    while (num > 0)
    {
        cin >> goal;
        
        cout << one_two_three(goal, 0, 0) << endl;
        
        num--;        
    }
    
}