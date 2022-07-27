#include <iostream>
#include <queue>

using namespace std;

int N, inp;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pair<int, int> pqTop;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        if(inp < 0) pq.push(make_pair(-inp, -1));
        else if(inp > 0) pq.push(make_pair(inp, 1));
        else {
            if(pq.empty()) cout << 0 << '\n'; // pq 가 비었는데 pop 요청이 들어올 경우 0 출력
            else{
                cout << pq.top().first * pq.top().second << '\n';
                pq.pop();
            }
        }
    }
    
    return 0;
}
