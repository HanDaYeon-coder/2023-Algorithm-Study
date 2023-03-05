#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int k = 0;

bool compare(vector<int> a, vector<int> b){
    if(a[k]==b[k])  return a[0] > b[0];
    return a[k] < b[k];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    k = col-1;
    
    sort(data.begin(), data.end(), compare);
    
    int result_sum = 0;
    for(int i=row_begin-1; i<row_end; i++){
        int result = 0;
        for(int j=0; j<data[0].size(); j++){
            result += data[i][j] % (i+1);
        }
        result_sum = result_sum ^ result;
    }
    return result_sum;
}
