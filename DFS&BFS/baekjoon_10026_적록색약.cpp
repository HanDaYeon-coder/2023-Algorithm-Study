#include <iostream>
using namespace std;

int N = 0;
int arrRGB[100][100]; //빨간색이 있는 구역 = 1, 파랜색이 있는 구역 = 2, 초록색이 있는 구역 = 3
int arrGB[100][100];
int areaRGB = 0;    //적록색약이 아닌 사람이 보는 구역의 수
int areaRG = 0; //적록색약인 사람이 보는 구역의 수

void dfs(int x, int y, int color){
    arrRGB[x][y] = 0;

    if(y-1 >= 0 and arrRGB[x][y-1] == color)    dfs(x, y-1, color);    
    if(y+1 < N and arrRGB[x][y+1] == color)     dfs(x, y+1, color);
    if(x+1 < N and arrRGB[x+1][y] == color)     dfs(x+1, y, color);    
    if(x-1 >= 0 and arrRGB[x-1][y] == color)    dfs(x-1, y,color);
}

void dfs2(int x, int y, int color){
    arrGB[x][y] = 0;

    if(y-1 >= 0 and arrGB[x][y-1] == color)    dfs2(x, y-1, color);    
    if(y+1 < N and arrGB[x][y+1] == color)     dfs2(x, y+1, color);
    if(x+1 < N and arrGB[x+1][y] == color)     dfs2(x+1, y, color);    
    if(x-1 >= 0 and arrGB[x-1][y] == color)    dfs2(x-1, y,color);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    string a;

    for(int i=0; i<N; i++){
        cin>>a;
        for(int j=0; j<N; j++){
            if(a[j]=='R'){
                arrRGB[i][j] = 1;   
                arrGB[i][j] = 1;
            }
            else if(a[j]=='B'){
                arrRGB[i][j] = 2;
                arrGB[i][j] = 2;
            }
            else {
                arrRGB[i][j] = 3;
                arrGB[i][j] = 1;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arrRGB[i][j] != 0) {
                dfs(i,j,arrRGB[i][j]);
                areaRGB +=1;
            }
            if(arrGB[i][j] != 0){
                dfs2(i,j,arrGB[i][j]);
                areaRG += 1;
            }
        }
    }

    cout<<areaRGB<<" "<<areaRG;
}
