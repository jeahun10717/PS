#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, x, popElt;
priority_queue<int, vector<int>, less<int>> pq;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if(pq.empty() && x == 0) cout << 0 << '\n';
        else if(x == 0){
            cout << pq.top() << '\n';
            pq.pop();
        }
        else pq.push(x);
    }

    return 0;
}
