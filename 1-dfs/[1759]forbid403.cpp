#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int L, C;
vector <char> v;
vector <string> ans;
int check[16];
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

bool checkValid(string now){
    int vowels = 0;
    int constants = 0;
    int hasVowel = false;

    for(int i=0; i<now.length(); i++){
        for(int j=0; j<5; j++){
            if(now[i] == vowel[j]){
                vowels++;
                hasVowel = true;
                break;
            }
        }
        if(!hasVowel){
            constants++;
        }
        hasVowel = false;
    }

    if(vowels >= 1 && constants >= 2) return true;
    return false;
}

//a c i s t w
void recursion(string now, int cur){

    if(L == now.length()){
        if(checkValid(now)){
            ans.push_back(now);
        }
        return;
    }

    for(int i=cur; i<v.size(); i++){
        if(!check[i]){
            check[i] = 1;
            recursion(now + v[i], i+1);
            check[i] = 0;
        }
    }
}

int main(){
    cin >> L >> C;

    for(int i=0; i<C; i++){
        char input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    recursion("", 0);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}