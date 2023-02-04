#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(),greater<int>());
    
    int idx = people.size()-1;
    for(int i=0; i<=idx; i++){
        if(people[i] + people[idx] <= limit){
            idx--;
        }
        answer++;
    }
    
    return answer;
}
