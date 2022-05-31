#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T, M, N, K, X, Y;
int wormCnt;
int field[51][51];
int visitArr[51][51];
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };


void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visitArr[y][x] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nX = x + dir[k][1];
            int nY = y + dir[k][0];
            if(nX >= 0 && nY >= 0 && nX <= M - 1 && nY <= N - 1){
                if(field[nY][nX] == 1 && visitArr[nY][nX] == 0){
                    q.push(make_pair(nY, nX));
                    visitArr[nY][nX] = 1;
                }
            }
            
        }
        
    }
}

int main(void){
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++) {
            cin >> X >> Y;
            field[Y][X] = 1;
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if(visitArr[y][x] == 0 && field[y][x] == 1){
                    BFS(x, y);
                    wormCnt++;
                }
            }
        }
        cout << wormCnt << '\n';
        wormCnt = 0;
        memset(visitArr, 0 , sizeof(visitArr));
        memset(field, 0, sizeof(field));
    }
    
    
    
    return 0;
}
