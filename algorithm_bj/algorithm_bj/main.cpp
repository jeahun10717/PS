#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;

long long int T, n, inp;
vector <long long int> minVec;
vector <long long int> maxVec;

int main(void){

    freopen("gain.inp", "r", stdin);
    freopen("gain.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        priority_queue<long long int, vector<long long int>, less<long long int>> maxPQ;
        priority_queue<long long int, vector<long long int>, greater<long long int>> minPQ;
        for (int j = 0; j < n; j++) {
            cin >> inp;
            maxPQ.push(inp);
            minPQ.push(inp);
        }
        long long int result = maxPQ.top() - minPQ.top();
        maxPQ.pop(); minPQ.pop();
        result = result + maxPQ.top() - minPQ.top();
        cout << result << '\n';
    }
    
    return 0;
}
