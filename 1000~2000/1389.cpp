#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int M, N, A, B;
int friendArr[102][102];
int kbArr[102];
int check[102];

int BFS(int start, int friendNum){
    
    memset(check, -1, sizeof(int)*(friendNum + 1));
    queue<int> q;
    check[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 1; i <= friendNum; i++) {
            if(friendArr[x][i] == 1 && check[i] == -1){
                check[i] = check[x] + 1;
                q.push(i);
            }
        }
    }
    int KBGNum = 0;
    for (int i = 1; i <= friendNum; i++) {
        KBGNum += check[i];
    }
    memset(check, 0, sizeof(int) * friendNum);
    return KBGNum;
    
}

int main(void){
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        friendArr[A][B] = 1; friendArr[B][A] = 1;
    }
    int MIN = 987654321; int minIdx = 0;
    for (int i = 1; i <= N; i++) {
        kbArr[i] = BFS(i, N);
        if(kbArr[i] < MIN){
            MIN = kbArr[i];
            minIdx = i;
        }
    }
    
    cout << minIdx << '\n';
    
    return 0;
}
