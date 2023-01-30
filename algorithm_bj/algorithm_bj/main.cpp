#include <iostream>
#include <fstream>
#include <tuple>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning(disable: 4996)

using namespace std;

int T, P, K, S;
int dp[11][8][1000000][8]; // (P, K, S, prevNode)

void coinMove(){
    
    for (int pIdx = 0; pIdx <= 10; pIdx++) {
        for (int kIdx = 0; kIdx <= 7; kIdx++) {
            bool sbreak = false;
            for (int sIdx = 0; !sbreak && sIdx <= 1000000; sIdx++) {
                for (int prevIdx = 0; !sbreak && prevIdx <= 7; prevIdx++) {
                    if(sIdx == 0){
                        dp[pIdx][kIdx][sIdx][prevIdx] = 0;
                        continue;
                    }else if(sIdx == 1){
                        dp[pIdx][kIdx][sIdx][prevIdx] = 1;
                        continue;
                    }
                    
                    if(pIdx != 0 && sIdx != 0 && sIdx % pIdx == 0){ // p 의 배수인 부분은 안봐도 됨
                        sbreak = true;
                        break;
                    }
                    bool kbreak = false;
                    for (int k = 1; k <= kIdx; k++) {
                        if(kIdx - k >= 0){ // k 개 전의 것을 볼 때 0 보다 크면서
                            int nextK = kIdx - k;
                            if(dp[pIdx][nextK][sIdx][prevIdx] ){ //
                                
                            }
                        }
                    }
                    
                }
            }
        }
    }
}

int main(void) {
    
//    freopen("coin.inp", "r", stdin);
//    freopen("coin.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
//    cin >> T;
//    for (int i = 0; i < T; i++) {
//        cin >> P >> K >> S;
//    }
    int cnt = 0;
//    for(int i = 2; i < 1; i++){
//        cnt++;
//    }
    cout << cnt;
    
    return 0;
}

