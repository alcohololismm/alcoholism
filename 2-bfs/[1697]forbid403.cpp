#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;
int n, k;
int visit[MAX];
queue <int> q;
void solve(){

    while(!q.empty()){
        int top = q.front();
        if(top == k) break;
        q.pop();

        int next_x = top - 1;
        if(next_x >= 0 && !visit[next_x]) {q.push(next_x); visit[next_x] = visit[top] + 1;}

        next_x = top + 1;
        if(next_x < MAX && !visit[next_x]) {q.push(next_x); visit[next_x] = visit[top] + 1;}

        next_x = top * 2;
        if(next_x < MAX && !visit[next_x]) {q.push(next_x); visit[next_x] = visit[top] + 1;}

    }
}
int main() {

    cin >> n >> k;
    q.push(n);
    visit[n] = 1;

    solve();

    cout << visit[k]-1 << endl;

    return 0;
}