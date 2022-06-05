#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dp[3][100001];
int N;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    dp[0][0] = 1; dp[1][0] = 1; dp[2][0] = 1;
    dp[0][1] = 3; dp[1][1] = 2; dp[2][1] = 2;
    dp[0][2] = 7; dp[1][2] = 5; dp[2][2] = 5;
    for (int i = 3; i < N; i++) {
        dp[0][i] = (dp[0][i-1] % 9901 + dp[1][i-1] % 9901 + dp[2][i-1] % 9901) % 9901;
        dp[1][i] = (dp[0][i-1] % 9901 + dp[2][i-1] % 9901) % 9901;
        dp[2][i] = (dp[0][i-1] % 9901 + dp[1][i-1] % 9901) % 9901;
    }
    
    cout << (dp[0][N-1] + dp[1][N-1] + dp[2][N-1]) % 9901 << '\n';
    
    
    return 0;
}
