#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int>pockets;
    
    for(int num : nums){
        pockets.insert(num);
    }
    
    if(pockets.size() <= nums.size()/2){
        answer = pockets.size();
    }
    else{
        answer = nums.size()/2;
    }
    
    return answer;
}
