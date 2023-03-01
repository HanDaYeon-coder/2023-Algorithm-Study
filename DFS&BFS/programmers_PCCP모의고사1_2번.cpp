#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool students[11] = {false, };
vector<int> selected_students;
int answer = 0;

void permutation(vector<vector<int>> ability, int students_num, int cnt){
    if(cnt == students_num){
        int ability_sum = 0;
        for(int i=0; i<students_num; i++){
            ability_sum += ability[selected_students[i]][i];
        }
        answer = max(answer, ability_sum);
        return;
    }
    
    for(int i=0; i< ability.size(); i++){
        if(!students[i]){
            students[i] = true;
            selected_students.push_back(i);
            permutation(ability, students_num, cnt+1);
            selected_students.pop_back();
            students[i] = false;
        }
    }
}

int solution(vector<vector<int>> ability) {
    permutation(ability,ability[0].size(),0);
    return answer;
}
