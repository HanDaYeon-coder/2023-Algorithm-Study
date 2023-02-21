#include <string>
#include <queue>
#include <vector>
using namespace std;

int sales[4] = {10, 20, 30, 40};
vector<double> sale;
priority_queue<pair<int,int>> pq;

void permutation_r(vector<vector<int>> users, vector<int> emotis){
    if(sale.size() == emotis.size()){
        int emoticons_plus = 0; //이모티콘 플러스 서비스 가입자수
        int prices_sum = 0;  //총 판매액
        
        for(int i=0; i<users.size(); i++){
            int price = 0;
            for(int j=0; j<emotis.size(); j++){
                if( sale[j] >= users[i][0]){
                    price += (emotis[j] * (100-sale[j])/100);
                }
            }
            if(price >= users[i][1]){
                emoticons_plus++;
            }
            else{
                prices_sum+=price;
            }
        }
        pq.push({emoticons_plus, prices_sum});
        
        return;
    }
    
    for(int i=0; i<4; i++){
        sale.push_back(sales[i]);
        permutation_r(users, emotis);
        sale.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {    
    permutation_r(users, emoticons);
    return {pq.top().first, pq.top().second};
}
