#include <iostream>
#include <vector>

using namespace std;

int N, K, inp;
vector<int> coin;

int main (void){
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        coin.push_back(inp);
    }
    
    int coinRoop = coin.size() - 1;
    int coinCnt = 0;
    while(true){
        if(K - coin[coinRoop] < 0) coinRoop--;
        if(K - coin[coinRoop] == 0) {
            coinCnt++;
            break;
        }
        if(K - coin[coinRoop] > 0){
            K = K - coin[coinRoop];
            coinCnt++;
        }
    }
    
    cout << coinCnt << '\n';
    
    return 0;
}
