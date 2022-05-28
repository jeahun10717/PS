#include <iostream>

using namespace std;

int N, inp;
long long int dp[101];

int main(void){
    
    dp[0] = 1; dp[1] = 1; dp[2] = 1; dp[3] = 2;
    dp[4] = 2; dp[5] = 3; dp[6] = 4;
    for (int i = 7; i < 102; i++) {
        dp[i] = dp[i-5] + dp[i-1];
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        cout << dp[inp - 1] << '\n';
    }
    
    return 0;
}
