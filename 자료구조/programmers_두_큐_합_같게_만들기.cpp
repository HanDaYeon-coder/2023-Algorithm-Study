#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    ll queue1_sum = 0, queue2_sum = 0;
    queue<int> que1, que2;
    
    for(int i : queue1){
        queue1_sum += i;
        que1.push(i);
    }
    
    for(int i : queue2){
        queue2_sum += i;
        que2.push(i);
    }
    
    if((queue1_sum + queue2_sum) % 2 == 1){
        return -1;
    }
    
    int len_que1 = que1.size();
    int len_que2 = que2.size();
    
    while(queue1_sum != queue2_sum){
        if(answer > (len_que1+len_que2+2)){
            return -1;
        }
        if(queue1_sum > queue2_sum){
            int num = que1.front();
            que1.pop();
            que2.push(num);
            queue1_sum -= num;
            queue2_sum += num;
        }
        else if(queue1_sum < queue2_sum){
            int num = que2.front();
            que2.pop();
            que1.push(num);
            queue1_sum += num;
            queue2_sum -= num;
        }
        answer++;
    }
    return answer;
}
