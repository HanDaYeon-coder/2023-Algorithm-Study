#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";    
    vector<char> numbers;
    map<char,int> numbers_idx;
    
    for(int i=0; i<26; i++){
        char x = 'a' + i;
        bool is_skip = false;
        for(int j=0; j<skip.size(); j++){
            if(x == skip[j]){
                is_skip = true;
                break;   
            }
        }
        if(!is_skip){
            numbers.push_back(x);
            numbers_idx[x] = numbers.size()-1;
        }
    }
    
    for(int i=0; i<s.size(); i++){
        int s_idx = numbers_idx[s[i]];
        answer += numbers[(s_idx + index) % numbers.size()];
    }
    
    return answer;
}
