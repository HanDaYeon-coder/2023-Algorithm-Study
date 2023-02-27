#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int>> nums;
    
    for (int i = 0; i < numbers.size(); i++){
        while (!nums.empty()){
            pair<int, int> top = nums.top();
            
            if (top.first >= numbers[i]){
                break;
            }
            answer[top.second] = numbers[i];
            nums.pop();
        }
        nums.push({ numbers[i], i });
    }
    return answer;
}
