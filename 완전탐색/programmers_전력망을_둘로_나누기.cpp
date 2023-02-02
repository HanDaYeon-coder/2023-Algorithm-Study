#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> graph[101];
bool check[101];
int num1 = 0;

int dfs(int here, int cnt){
    check[here] = 1;
    for(int i=0; i<graph[here].size(); i++){
        int next = graph[here][i];
        if(check[next] == 0){
            cnt = dfs(next, cnt+1);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for(int i=0; i<wires.size(); i++){
        int first = wires[i][0];    int second = wires[i][1];
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    
    for(int i=0; i<wires.size(); i++){
        memset(check,false,101);
        int first = wires[i][0];    int second = wires[i][1];
        check[first] = true; check[second] = true;    //전선 연결 끊기
        int var1 = dfs(first, 0);   int var2 = dfs(second, 0);
        answer = min(abs(var1-var2), answer);
    }
    
    return answer;
}
