#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int n, T, cnt;
int num[3] = {1, 2, 3};
int check[12];
//1, 2, 3의 합으로 나타내기

void recursion(int target, int cur){
    if(target < 0) {
        return;
    }
    if(target == 0){
        cnt++;
        return;
    }

    for(int i=cur; i<3; i++){
        recursion(target - num[i], cur);
    }

}

int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        cnt = 0;
        cin >> n;

        recursion(n, 0);
        cout << cnt << endl;
    }



    return 0;
}