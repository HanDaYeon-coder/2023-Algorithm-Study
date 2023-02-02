#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

char words[5] = {'A','E', 'I', 'O', 'U'};
map<string,bool> check;
long long cnt = 0;
long long answer = 0;

void dfs(string here, string word1){
    check[here] = true;
    if(here == word1){
        answer = cnt;
        return;
    }
    if(here.size() >= 6){
        return;
    }
    cnt++;
    for(int i=0; i<5; i++){
        string new_here = here+words[i];
        if(check[new_here] != true){
            dfs(new_here, word1);
        }
    }
}

int solution(string word) {
    dfs("",word);
    return answer;
}
