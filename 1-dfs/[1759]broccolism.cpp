#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int len, num_of_alphas, cons, vols;
vector<char> alphas;

//true: 모음
/*a: 97, e: 101, i: 105, o: 111, u: 117*/
//false: 자음
bool is_vowel(int i, string checkMe)
{
    if (checkMe[i] == 97 || checkMe[i] == 101 || checkMe[i] == 105 ||
    checkMe[i] == 111 || checkMe[i] == 117)
        return true;
    else
        return false;    
}

void password(string so_far, int next)
{        
    if (so_far.size() == len) //done! but not completely.
    {
        cons = 0;
        vols = 0;
        for (int i = 0; i < len; ++i)
        {
            if (is_vowel(i, so_far))
                ++vols;
            else
                ++cons;
        }

        if (vols >= 1 && cons >= 2) // good!
            cout << so_far << endl;
    }
    else if (next == num_of_alphas)
    {
        return;
    }
    else
    {
        password(so_far + alphas[next], next + 1);
        password(so_far, next + 1);
    }
}

int main()
{
    /*we just need to PICK alphabets and then sort!*/

    //get input first.
    cin >> len >> num_of_alphas;
    int i = 0;
    char input;
    while (i < num_of_alphas)
    {
        cin >> input;
        alphas.push_back(input);
        ++i;
    }

    //and then SORT!
    sort(alphas.begin(), alphas.end());

    string inputs = "";
    for (int i = 0; i < num_of_alphas; ++i)
        inputs += alphas[i];
        
    /* then, check input alphabets.
    we need at least 1 모음 and 2 자음!*/
    int con = 0;
    int vol = 0;
    for (i = 0; i < num_of_alphas; ++i)
    {
        if (is_vowel(i, inputs))
            ++vol;
        else
            ++con;        
    }

    if (con < 2 || vol < 1)
        return 0;
    
    password("", 0);
}