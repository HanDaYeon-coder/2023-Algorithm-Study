#include <iostream>
#include <queue>
#include <map>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int puzzle[3][3];
    string init_puzzle;
    map<string, bool> m;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>puzzle[i][j];
            init_puzzle += (puzzle[i][j] + '0');
        }
    }

    queue<pair<string,int>> que;
    que.push({init_puzzle,0});
    m[init_puzzle] = true;

    while(!que.empty()){
        string here = que.front().first;
        int depth = que.front().second;
        que.pop();

        if(here == "123456780"){
            cout<<depth<<"\n";
            return 0;
        }

        for(int i=0; i<here.size(); i++){
            if(here[i] == '0'){
                for(int j=0; j<4; j++){
                    string new_puzzle = here;
                    int X = (i/3) + dx[j];
                    int Y = (i%3) + dy[j];
                    if(X < 0 or X >= 3 or Y <0 or Y >= 3){
                        continue;
                    }
                    new_puzzle[i] = new_puzzle[X*3+Y];
                    new_puzzle[X*3+Y] = '0';
                    if(!m[new_puzzle]){
                        que.push({new_puzzle, depth+1});
                        m[new_puzzle] = true;
                    }
                }
                break;
            }
        }
    }

    cout<<-1<<"\n";
    return 0;
}
