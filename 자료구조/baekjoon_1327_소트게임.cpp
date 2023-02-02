#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K =0;
    char nums;
    string numbers;
    string origin_numbers;
    map<string, bool> map1;
    int ans = -1;
    cin>>N>>K;
    
    for(int i=0; i<N; i++){
        cin >> nums;
        numbers += nums;
    }

    origin_numbers = numbers;
    sort(numbers.begin(), numbers.end());   //구하고자 하는 오름차순 정렬
    
    queue<pair<string,int>> que;
    que.push({origin_numbers,0});

    while(!que.empty()){
        string here = que.front().first;
        int depth = que.front().second;

        if(here == numbers){
            ans = depth;
            break;
        }
        que.pop();

        if(map1[here] != true){
            for(int i=0; i<=N-K; i++){
                string num1 = here.substr(0,i);
                string num2 = here.substr(i, K);
                reverse(num2.begin(), num2.end());
                string num3 = here.substr(K+i,N);
                que.push({num1+num2+num3,depth+1});
            }
            map1[here] = true;
        }
    }

    cout<<ans<<"\n";
}
