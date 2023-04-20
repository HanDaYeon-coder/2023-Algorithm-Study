#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }
    return gcd(b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answerA = 0;
    int answerB = 0;
    int answer = 0;
    
    int resA = arrayA[0];
    int resB = arrayB[0];
    
    for(int i=1; i<arrayA.size(); i++){
        resA = gcd(arrayA[i], resA);
    }
    
    for(int i=1; i<arrayB.size(); i++){
        resB = gcd(arrayB[i], resB);
    }
    
    answerA = resA;
    answerB = resB;
    
    for(int i=0; i<arrayA.size(); i++){
        if(arrayA[i]%resB == 0){
            answerB = 0;
            break;
        }
    }
    
    for(int i=0; i<arrayB.size(); i++){
        if(arrayB[i]%resA == 0){
            answerA = 0;
            break;
        }
    }
    
    answer = max(answerA, answerB);
    
    return answer;
}
