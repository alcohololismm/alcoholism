#include <iostream>
#include <algorithm>

using namespace std;

int get_num(int cur, int goal){
    if(cur > goal) return 0;
    if(cur == goal) return 1;
    return get_num(cur+1, goal)+get_num(cur+2, goal)+get_num(cur+3, goal);
}

int main(void){
    int N, tmp;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        cout << get_num(0,tmp);
    }
}