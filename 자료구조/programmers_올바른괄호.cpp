#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> a;   //'(' : 1, ')' : 0
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            a.push(1);
        }
        else{
            if(a.empty()) { //')'가 이전에 선언된 '('보다 많은 경우
                answer = false;
                break;
            }
            a.pop();
        }
    }
    
    if(!a.empty()) answer = false;  //'('가 남아있는 경우
    return answer;
}
