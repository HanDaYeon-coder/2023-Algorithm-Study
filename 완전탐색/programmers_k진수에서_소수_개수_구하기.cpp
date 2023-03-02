#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool prime_check(long n){
    if (n == 1) return false;
    for(long i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> nums;
    vector<int> zero_idx;
    
    while(n>0){
        int num = n % k;
        n = n / k;
        nums.push_back(num);
    }
    
    reverse(nums.begin(), nums.end());
    
    zero_idx.push_back(-1);
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0){
            zero_idx.push_back(i);
        }
    }
    zero_idx.push_back(nums.size());
    
    for(int i=0; i<zero_idx.size()-1; i++){
        if(zero_idx[i+1]-zero_idx[i] > 1){
            long prime_number = 0;   int pow_num = 0;
            for(int j=zero_idx[i+1]-1; j>zero_idx[i]; j--){
                prime_number = prime_number + nums[j] * pow(10, pow_num);
                pow_num++;
            }
            if(prime_check(prime_number)){
                answer++;
            }
            
        }
    }
    
    return answer;
}
