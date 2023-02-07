#include <iostream>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int g = 0, s =0;
    string W;   string S;

    int gArray[60] = {0,};
    int sArray[60] = {0,};
    int answer = 0;

    cin>>g>>s;
    cin>>W>>S;
    
    for(int i=0; i<g; i++){
        gArray[W[i]-'A'] += 1;
    }

    for(int i=0; i<g; i++){
        sArray[S[i]-'A'] += 1;
    }

    answer++;
    for(int j=0; j<g; j++){
        if(gArray[W[j]-'A'] != sArray[W[j]-'A']){
            answer--;
            break;
        }
    }

    for(int i=g; i<s; i++){
        sArray[S[i]-'A'] += 1;
        sArray[S[i-g]-'A'] -= 1;

        answer++;
        for(int j=0; j<g; j++){
            if(gArray[W[j]-'A'] != sArray[W[j]-'A']){
                answer--;
                break;
            }
        }
    }
    cout<<answer<<"\n";
}
