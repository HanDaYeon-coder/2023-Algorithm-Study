#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    char score[8] = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    map<char,int> scores; //성격 유형별 점수
    
    int idx=0;
    for(int i=0; i<survey.size(); i++){
        char first = survey[i][0];
        char second = survey[i][1];
        int choice = choices[idx];
        
        if(choice > 4){
            scores[second] += (choice - 4);
        }
        else if(choice < 4){
            scores[first] += (4 - choice);
        }
        idx++;
    }
    
    for(int i=0; i<8; i+=2){
        int first_character = scores[score[i]];
        int second_character = scores[score[i+1]];
        
        if(first_character == second_character){
            answer += score[i];
        }
        else if(first_character > second_character){
            answer += score[i];
        }
        else{
            answer += score[i+1];
        }
    }
    
    return answer;
}
