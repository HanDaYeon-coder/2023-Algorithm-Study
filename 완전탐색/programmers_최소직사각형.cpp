#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    priority_queue<int> width;
    priority_queue<int> length;
        
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            width.push(sizes[i][1]);
            length.push(sizes[i][0]);
        }
        else{
            width.push(sizes[i][0]);
            length.push(sizes[i][1]);
        }
    }
    
    return width.top()*length.top();
}
