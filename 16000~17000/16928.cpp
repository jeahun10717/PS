#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M, x, y;
int INF = 987654321;
int graph[102][102];
bool check[102];
int dist[102];

int getSmallIndex(int nodeCnt){
    int min = INF;
    int index = 0;
    for (int i = 0; i < nodeCnt; i++) { // node 의 개수만큼 for 문을 돌면서
        if(dist[i] < min && !check[i]){ // 방문하지 않은 노드들 중에 min 값을 찾는다
            min = dist[i];
            index = i;
        }
    }
    return index; // min 값을 가지는 index 를 return
}

void dijkstra(int start, int nodeCnt){
    for (int i = 0; i < nodeCnt; i++) {
        // start 노드에서 연결된 노드들에 distance 를 구해서 거리배열에 저장한다.
        dist[i] = graph[start][i];
    }
    check[start] = true; // 시작노드를 방문체크
    for (int i = 0; i < nodeCnt - 2; i++) {// 시작점을 제외 + 마지막 노드 제외 때문에 nodeCnt - 2 로 설정함.
        int current = getSmallIndex(nodeCnt); // current 변수에 현재 방문이 가능한 노드들 중 가장 작은 노드의 인덱스를 저장
        check[current] = true; // 위에서 찾은 가장 작은 거리의 노드를 방문체크 한다.
        for (int j = 0; j < nodeCnt; j++) {
            // 마지막 노드를 제외하는 이유는 마지막노드를 방문하기 전 모든 노드를 방문했을 경우
            // 마지막 노드는 갈 곳이 없기 때문에 거리 갱신이 이루어지지 않기 때문이다
            if(!check[j]){ // 방문하지 않은 노드들 중
                
                // current 까지오는 최소 경로비용 + current 에서 j 까지 가는비용이 j 노드에 저장되어 있는 거리비용보다 짧을 때만
                if(dist[current] + graph[current][j] < dist[j]){
                    dist[j] = dist[current] + graph[current][j]; // j 노드를 갱신한다.
                }
            }
        }
    }
}

int main(void){
    
    cin >> N >> M;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if(i + dice < 100) { // 주사위로 갈 수 있는 범위인 99를 넘지 않고(문제에서는 100으로 주어짐)
                graph[i][i + dice] = 1;
            }
        }
    }
    
    for (int i = 0; i < N + M; i++) {
        cin >> x >> y;
        for (int j = 0; j < 100; j++) {
            if(x - 1 == j) graph[j][j] = 0;
            else graph[x - 1][j] = INF;
        }
        graph[x - 1][y - 1] = 0;
    }
    dijkstra(0, 100);
    
    cout << dist[99] << '\n';
    
    return 0;
}
