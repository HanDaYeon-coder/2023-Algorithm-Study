#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[9] = {0,};
vector<int> v;
int answer = -1;

void combination(int cnt, vector<vector<int>> x, int k){
    if(cnt == x.size()){
        int cnt_dungeons = 0;
        for(int i : v){
            if(k >= x[i][0]){
                k -= x[i][1];
                cnt_dungeons++;
            }
        }
        answer = max(answer, cnt_dungeons);
       return; 
    }
    for(int i=0; i<x.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            combination(cnt+1, x, k);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    combination(0, dungeons, k);
    return answer;
}
