#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    long sequence_sum = sequence[0];
    int start_idx = 0;
    int end_idx = 0;
    int sequence_size = 20000000;
    int ans1 = 0, ans2 = 0;
        
    while(start_idx <= end_idx){
        if(sequence_sum < k){
            if(end_idx == sequence.size()-1){
                break;
            }
            end_idx++;
            sequence_sum += sequence[end_idx];
        }
        else if(sequence_sum == k){
            if(sequence_size > (end_idx - start_idx)){
                ans1 = start_idx;
                ans2 = end_idx;
                sequence_size = (end_idx - start_idx);
            }
            sequence_sum -= sequence[start_idx];
            start_idx++;
        }
        else{
            sequence_sum -= sequence[start_idx];
            start_idx++;
        }
    }
    
    return {ans1, ans2};
}
