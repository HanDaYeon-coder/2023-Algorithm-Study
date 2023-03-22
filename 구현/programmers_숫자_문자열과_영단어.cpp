#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    string answer;
    string num;
    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(int i=0; i<s.size(); i++){
        if(s[i] <= '9' and s[i] >= '0'){
            answer += s[i];
        }
        else{
            num += s[i];
            for(int i=0; i<10; i++){
                if(num == numbers[i]){
                    answer += ('0' + i);
                    num = "";
                    break;
                }
            }
        }
    }
    
    return stoi(answer);
}
