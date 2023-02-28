#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int cards1_idx = 0, cards2_idx = 0;
    for(int i=0; i<goal.size(); i++){
        if(goal[i] == cards1[cards1_idx]){
            cards1_idx++;
        }
        else if(goal[i] == cards2[cards2_idx]){
            cards2_idx++;
        }
        else{
            return "No";
        }
    }
    
    return "Yes";
}
