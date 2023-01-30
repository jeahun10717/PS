#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <typeinfo>

using namespace std;

int dp[3][10001];
int elv[10001];
int N, inp;

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> inp;
        elv[i] = inp;
    }
    
    dp[0][0] = 0; dp[1][0] = elv[0]; dp[2][0] = 0;
    
    dp[0][1] = elv[0];
    dp[1][1] = elv[1];
    dp[2][1] = elv[0] + elv[1];
    
    dp[0][2] = elv[0] + elv[1];
    dp[1][2] = elv[0] + elv[2];
    dp[2][2] = elv[1] + elv[2];
    
    for (int i = 3; i < N; i++) {
        dp[0][i] = max({dp[1][i-1], dp[2][i-1]});
        dp[1][i] = max({dp[1][i-2] + elv[i], dp[2][i-2] + elv[i]});
        dp[2][i] = max({dp[1][i-3] + elv[i] + elv[i-1], dp[2][i-3] + elv[i] + elv[i-1]});
    }
    
    cout << max(dp[1][N-1], dp[2][N-1]) << '\n';
    
    return 0;
}
