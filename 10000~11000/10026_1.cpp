#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
#include <string>

using namespace std;

int N;
char inp;
int colorArr[3]; // 0 은 R, 1 은 G, 2 는 B
char grid[101][101];
int check[101][101];
int dir[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}}; // y, x 순서

void BFS_RGB(int stY, int stX, char color){
    // 다른 색으로 처음 들어왔을 때 해당색 구역 하나 올려줌
    if(color == 'R') colorArr[0]++;
    else if(color == 'G') colorArr[1]++;
    else if(color == 'B') colorArr[2]++;
    
    check[stY][stX] = 1;
    queue<tuple<int, int>> q;
    q.push(make_tuple(stY, stX));
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];
            if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < N){ // y 와 x 가 범위를 넘어서지 않을 때
                if(check[nextY][nextX] == 0){ // 방문할 다음 노드가 방문하지 않은 노드일 때
                    if(grid[nextY][nextX] == color){ // 방문할 다음 노드가 같은 색상일 때만 진행
                        check[nextY][nextX] = 1;
                        q.push(make_tuple(nextY, nextX));
                    }
                }
            }
        }
    }
    
}

void BFS_RB(int stY, int stX, char color){
    // 다른 색으로 처음 들어왔을 때 해당색 구역 하나 올려줌
    if(color == 'R') colorArr[0]++;
    else if(color == 'G') colorArr[1]++;
    else if(color == 'B') colorArr[2]++;
    
    check[stY][stX] = 1;
    queue<tuple<int, int>> q;
    q.push(make_tuple(stY, stX));
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];
            if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < N){ // y 와 x 가 범위를 넘어서지 않을 때
                if(check[nextY][nextX] == 0){ // 방문할 다음 노드가 방문하지 않은 노드일 때
                    if(color == 'B'){ // B 일 때는 같은 색만 진행
                        if(grid[nextY][nextX] == color ){ // 방문할 다음 노드가 같은 색상일 때만 진행
                            check[nextY][nextX] = 1;
                            q.push(make_tuple(nextY, nextX));
                        }
                    }else if(color == 'R'|| color == 'G'){ // R, G 일 때 진행
                        if(grid[nextY][nextX] == 'R' || grid[nextY][nextX] == 'G'){ // 방문할 다음 노드가 같은 색상일 때만 진행
                            check[nextY][nextX] = 1;
                            q.push(make_tuple(nextY, nextX));
                        }
                    }
                    
                }
            }
        }
    }
    
}

int main(void){
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inp;
            grid[i][j] = inp;
        }
    }
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if(check[y][x] == 0) BFS_RGB(y, x, grid[y][x]);
        }
    }
    cout << colorArr[0] + colorArr[1] + colorArr[2] << ' ';
    memset(check, 0, sizeof(check));
    memset(colorArr, 0, sizeof(colorArr));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if(check[y][x] == 0) BFS_RB(y, x, grid[y][x]);
        }
    }
    cout << colorArr[0] + colorArr[1] + colorArr[2] << '\n';
    
    return 0;
}
