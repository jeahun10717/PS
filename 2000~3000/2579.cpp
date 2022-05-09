#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <typeinfo>

using namespace std;

int dp[3][301];
int stair[301];
int N, inp;

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> inp;
        stair[i] = inp;
    }
    
    dp[0][0] = 0; dp[1][0] = stair[0]; dp[2][0] = 0;
    
    dp[0][1] = stair[0];
    dp[1][1] = stair[1];
    dp[2][1] = stair[0] + stair[1];
    
    dp[0][2] = stair[0] + stair[1];
    dp[1][2] = stair[0] + stair[2];
    dp[2][2] = stair[1] + stair[2];
    
    for (int i = 3; i < N; i++) {
        dp[0][i] = max({dp[1][i-1], dp[2][i-1]});
        dp[1][i] = max({dp[1][i-2] + stair[i], dp[2][i-2] + stair[i]});
        dp[2][i] = max({dp[1][i-3] + stair[i] + stair[i-1], dp[2][i-3] + stair[i] + stair[i-1]});
    }
    
    cout << max(dp[1][N-1], dp[2][N-1]) << '\n';
    
    return 0;
}
