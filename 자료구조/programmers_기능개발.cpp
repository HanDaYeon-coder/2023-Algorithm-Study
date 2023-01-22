#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> que;
    vector<int> answer;
    
    for(int i=0; i<progresses.size(); i++){
        int A = 100-progresses[i];  int B = speeds[i];
        
        if(A % B != 0)  que.push((A/B)+1);  //  ex) 작업 진도 = 1, 작업 속도 = 100인 경우 -> (100-1)/100 = 99/100 = 0으로 나오지만 실제로는 1일이므로
        else    que.push(A/B);  //  A/B는 기능개발까지 걸리는 일수
    }
    
    int cnt = 0;
    int here = que.front();
    
    while(!que.empty()){
        if(here >= que.front()){
            cnt++;
            que.pop();
        }
        else{
            answer.push_back(cnt);
            cnt = 0;
            here = que.front();
        }
    }
    
    answer.push_back(cnt);
    
    return answer;
}
