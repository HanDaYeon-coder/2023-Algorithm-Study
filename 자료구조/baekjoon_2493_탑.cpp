#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int N=0;    //테스트 케이스의 수
    int high = 0;   //탑의 높이
    
    stack<pair<int,int>> sta1;  //탑의 번호, 탑의 높이

    cin>>N;
    for(int n=1; n<=N; n++){
        cin>>high;

        while(true){
            if(sta1.empty()){
                cout<<0<<" ";
                sta1.push({n, high});
                break;
            }
            else{
                if(high > sta1.top().second) sta1.pop();    // '입력 받은 높이 > top의 높이'이면, stack의 top을 pop한다.
                else {
                    cout<<sta1.top().first<<" ";    // '입력 받은 높이 < top의 높이'이면, 해당 top의 탑 번호를 출력하고 
                    sta1.push({n, high});           //입력 받은 탑의 높이와 번호를 stack에 넣는다.
                    break;
                }
            }
        }
    }
}
