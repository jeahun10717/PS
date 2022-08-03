#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M, H, inp;
int tmt, ripeTmt, ripeTime, maxTime;
int graph[101][101][101];
//int check[101][101][101];
int dir[6][3] = { // x, y, z 순서
    {1, 0, 0},{-1, 0, 0},
    {0, 1, 0},{0, -1, 0},
    {0, 0, 1},{0, 0, -1}
};
queue<tuple<int, int, int, int>> q; // x, y, z, ripeTime;

void BFS(){
    maxTime = -1;
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        ripeTime = get<3>(q.front());
        if(maxTime < ripeTime) maxTime = ripeTime;
        q.pop();
        for (int i = 0; i < 6; i++) {
            if(x + dir[i][0] < M && y + dir[i][1] < N && z + dir[i][2] < H
               && x + dir[i][0] >= 0 && y + dir[i][1] >= 0 && z + dir[i][2] >= 0){ // 진행할 노드방향의 노드가 N, M, H 범위 안에 존재하고
                if(graph[x + dir[i][0]][y + dir[i][1]][z + dir[i][2]] == 0){ // 진행할 방향의 노드가 토마토가 들어있고 익지 않았을 때(-1, 1 은 제외하고 진행)
                    graph[x + dir[i][0]][y + dir[i][1]][z + dir[i][2]] = 1; // 토마토를 익은 것으로 변경
                    q.push(make_tuple(x + dir[i][0], y + dir[i][1], z + dir[i][2], ripeTime + 1));
                    ripeTmt++; // 모든 토마토가 익었는지 확인하기 위한 변수를 하나 올려준다
                }
            }
            
        }
    }
}

int main(void){
    
    cin >> M >> N >> H;
    tmt = N * M * H;
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> inp;
                graph[x][y][z] = inp;
                if(inp == 1){
                    ripeTmt++;
                    q.push(make_tuple(x, y, z, 0)); // 익은 토마토가 들어있는 부분은 BFS 의 시작점으로 취급한다.
                }else if(inp == -1) tmt--;
            }
        }
    }
    if(ripeTmt == tmt){
        cout << 0 << '\n';
    }else{
        BFS();
        if(ripeTmt == tmt) { // 모든 토마토가 정상적으로 익었을 때
            cout << maxTime << '\n';
        }else { // 익지 못한 토마토가 존재할 때
            cout << -1 << '\n';
        }
    }
    
    return 0;
}
