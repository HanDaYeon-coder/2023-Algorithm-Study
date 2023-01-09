#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N = 0, a = 0;  //전체 용액의 수, 용액의 특성값
    set<int> ans;    //산성 용액의 특성값 (1 이상인 양수)

    cin>>N;
    while(N--){
        cin>>a;
        ans.insert(a);
    }

    set<int>::iterator s = ans.begin();
    set<int>::iterator e = --ans.end();

    int min = 2000000000;
    int ans1 = 0, ans2 = 0;

    while(*s < *e){
        int sum = *s + *e;

        if(min > abs(sum)){
            min = abs(sum);
            ans1 = *s;  ans2 = *e;
            if(sum == 0){
                break;
            }
        }

        if(sum < 0) ++s;
        else    --e;
    }
    cout<<ans1<<" "<<ans2;
}
