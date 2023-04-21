#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string A;
    string B;
    int answer = 100;
    cin>>A>>B;

    for(int i=0; i <= (B.length()-A.length()); i++){
        int diff = 0;
        for(int j=0; j<A.length(); j++){
            if(B[j+i] != A[j]){
                diff++;
            }
        }
        answer = min(answer, diff);
    }

    cout<<answer<<"\n";
    return 0;
}
