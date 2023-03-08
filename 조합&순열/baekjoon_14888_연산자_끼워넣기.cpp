#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;
vector<char> x;

int arr[12]={0,};
int abcd[4] = {0,};
char v2[4] = {'+','-','x','/'};
bool check[12] = {false,};
int minAnswer = 1e9;
int maxAnswer = -1e9;

void permutation(int cnt){
    if(cnt == v.size()){
        int answer = arr[0];
        for(int i=0; i < v.size(); i++){
            if(x[i] == '+'){
                answer = answer + arr[i+1];
            }
            else if(x[i] == '-'){
                answer = answer - arr[i+1];
            }
            else if(x[i] == 'x'){
                answer = answer * arr[i+1];
            }
            else{
                answer = answer / arr[i+1];
            }
        }
        minAnswer = min(minAnswer, answer);
        maxAnswer = max(maxAnswer, answer);
        return;
    }
    for(int i=0; i<v.size(); i++){
        if(!check[i]){
            check[i] = true;
            x.push_back(v[i]);
            permutation(cnt+1);
            x.pop_back();
            check[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    for(int i=0; i<4; i++){
        cin>>abcd[i];
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<abcd[i]; j++){
            v.push_back(v2[i]);
        }
    }
    
    permutation(0);

    cout<<maxAnswer<<"\n";
    cout<<minAnswer<<"\n";
}
