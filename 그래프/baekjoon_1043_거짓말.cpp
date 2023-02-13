#include <iostream>
#include <vector>
using namespace std;

int parent[51] = {0,};

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X == Y) return;
    parent[Y] = X;
}

bool is_parent(int x, int y){ //부모가 같은지 살펴본다.
    int X = find(x);
    int Y = find(y);

    if(X == Y) return true;
    return false;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

   int N = 0, M = 0;    //사람의 수, 파티의 수
    cin >> N >> M;

   int truthPeopleNums = 0; //이야기의 진실을 아는 사람의 수
   vector<int> truthPeople; //이야기의 진실을 아는 사람들의 번호
   vector<int> party[M];  //각 파티마다 오는 사람들의 번호
   
   int nums;
   cin >> truthPeopleNums;
   
    for(int i=0; i<truthPeopleNums; i++){
        cin>>nums;
        truthPeople.push_back(nums);
   }

   int partyNums = 0;   //각 파티마다 오는 사람의 수
   int answer = 0;
   
   for(int i=1; i<=N; i++){
        parent[i] = i;
   }

    for(int m=0; m<M; m++){
        cin>>partyNums;
        
        for(int i=0; i<partyNums; i++){
            cin>>nums;
            party[m].push_back(nums);
        }

        for(int i=0; i<partyNums-1; i++){
            int x = party[m][i];
            int y = party[m][i+1];
            merge(x,y);
        }
    }

    for(int i=0; i<M; i++){    //각각의 파티마다 진실을 아는 사람이 있는지 살펴본다.
        bool check = false;
        answer++;
        for(int j=0; j<party[i].size(); j++){
            for(int k=0; k<truthPeopleNums; k++){
                if(is_parent(parent[party[i][j]], parent[truthPeople[k]])){
                    answer--;
                    check = true;
                    break;
                }
            }
            if(check == true){
                break;
            }
        }
    }
    cout<<answer<<"\n";
}
