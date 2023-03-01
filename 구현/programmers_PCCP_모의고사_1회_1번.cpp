#include <string>
#include <vector>
using namespace std;

string solution(string input_string) {
    string answer = "";
    
    int alphabet[26] = {0, };   //알파벳 개수
    vector<char> s1;
    s1.push_back(input_string[0]);
    
    for(int i=0; i<input_string.size(); i++){
        if(s1[s1.size()-1] != input_string[i]){
            s1.push_back(input_string[i]);
        }
    }
    
    for(int i=0; i<s1.size(); i++){
        alphabet[s1[i] - 'a']++;
    }
    
    for(int i=0; i<26; i++){
        if(alphabet[i] > 1){
            answer += (i + 'a');
        }
    }
    
    if(answer == "")return "N";
  
    return answer;
}
