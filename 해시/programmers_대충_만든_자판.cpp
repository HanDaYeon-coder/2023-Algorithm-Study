#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> min_keys;    //해당 알파벳이 되기 위해서 눌러야 하는 최소 횟수
    
    for(int i=0; i<keymap.size(); i++){
        for(int j=0; j<keymap[i].size(); j++){
            if(min_keys[keymap[i][j]] == 0){
                min_keys[keymap[i][j]] = j+1;
            }
            else{
                min_keys[keymap[i][j]] = min(min_keys[keymap[i][j]], j+1);
            }
        }
    }
    
    for(int i=0; i<targets.size(); i++){
        int nums = 0;
        for(int j=0; j<targets[i].size(); j++){
            if(min_keys[targets[i][j]] == 0){
                nums = -1;
                break;
            }
            nums += min_keys[targets[i][j]];
        }
        answer.push_back(nums);
    }
    
    return answer;
}
