#include <string>
using namespace std;

int solution(int storey) {
    int answer = 0;
    int x = storey;
    int y = 0;
    
    while(x > 0){
        y = x%10;
        x = x/10;
        
        if(y > 5){
            answer += (10-y);
            x++;
        }
        else if(y<5){
            answer += y;
        }
        else{
            if(x%10 >= 5){
                answer += (10-y);
                x++;
            }
            else{
                answer += y;
            }
        }
    }
    return answer;
}
