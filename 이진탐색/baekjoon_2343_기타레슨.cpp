#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

   int N = 0, M =0; //총 강의 수, 총 블루레이의 개수
   cin >> N >> M;

    long long lecture_sum = 0;  //블루레이 개수가 N일때, 블루레이의 크기
    long long lecture_max = 0;  //블루레이 개수가 1일때, 블루레이의 크기
    long long lecture[N];

    for(int i=0; i<N; i++){
        cin>>lecture[i];
        lecture_sum += lecture[i];
        lecture_max = max(lecture_max, lecture[i]);
    }

    long long high = lecture_sum;
    long long low = lecture_max;
    long long mid = 0;

    while(low <= high){
        int cnt = 0;    //블루레이의 개수
        int sum = 0;
        mid = (high + low) / 2;

        for(int i=0; i<N; i++){
            sum += lecture[i];
            if(sum > mid){
                sum = lecture[i];
                cnt++;
            }
        }

        if(sum > 0){
            cnt++;
        }

        if(cnt > M){   //블루레이의 크기를 늘려야 한다.
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout<<low<<"\n";
    
}
