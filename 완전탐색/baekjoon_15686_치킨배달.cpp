#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N =0, M=0;  //도시의 크기, 치킨집의 최대 개수
vector<pair<int,int>> vec;
vector<pair<int,int>> home; //집의 번호, 집의 좌표
vector<pair<int,int>> chicken;  //치킨 집 번호, 치킨 집의 좌표
int min_homes_sum = 0x3f3f3f;
bool check[13];

void DFS(int idx, int cnt){
    if(cnt == M){
        int homes_sum = 0;
        for(int i=0; i<home.size(); i++){
            int min_home_sum = 0x3f3f3f;
            for(int j=0; j<vec.size(); j++){
                int sum = abs(vec[j].first-home[i].first) + abs(vec[j].second-home[i].second);
                if(sum < min_home_sum) min_home_sum = sum;    //집을 기준으로 치킨집까지의 거리 중 최단 거리를 구하기.
                
            }
            homes_sum = homes_sum + min_home_sum;
        }
        if(min_homes_sum > homes_sum) min_homes_sum = homes_sum;
        return;
    }

    for(int i=idx; i<chicken.size(); i++){
        if(check[i]==true) continue;
        check[i]=true;
        vec.push_back(chicken[i]);
        DFS(i,cnt+1);
        check[i]=false;
        vec.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int city=0;    //도시의 정보 (0 : 빈칸, 1 : 집, 2 : 치킨집)

    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>city;
            if(city == 1) home.push_back({i,j});
            else if(city == 2) chicken.push_back({i,j});
        }
    }

    //집을 기준으로 치킨집까지의 거리 중 최단 거리를 구하고, 집마다 최단 거리의 합 구하고, 최단 거리의 합 중 최소 구하기
    DFS(0,0);
    cout<<min_homes_sum<<"\n";
}
