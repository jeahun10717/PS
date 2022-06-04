#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dp[1000001];
vector<int> sixNumVec;
int N;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int sixNum = 0;
    for (int i = 1;; i++) {
        sixNum = 2*i*i - i;
        if(sixNum > 1000000) break;
        sixNumVec.push_back(sixNum);
        dp[sixNum] = 1;
    }
    dp[2] = 2; dp[3] = 3; dp[4] = 4; dp[5] = 5; dp[6] = 1; dp[7] = 2;
    dp[8] = 3; dp[9] = 4; dp[10] = 5; dp[11] = 6; dp[12] = 2;
    
    for (int i = 13; i <= N; i++) {
        int minCnt = 987654321;
        for (int sixRoop = 0; sixRoop < sixNumVec.size(); sixRoop++) {
            if(i < sixNumVec[sixRoop]) break;
            if(dp[i - sixNumVec[sixRoop]] == 6) continue;
            else minCnt = min(minCnt, dp[i - sixNumVec[sixRoop]]);
        }
        dp[i] = minCnt + 1;
    }
    
    cout << dp[N] << '\n';

    return 0;
}
