#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, inp;
int graph[101][101];
int outGrpah[101][101];
int check[101];

void DFS(int start){
    check[start]++;
//    outGrpah[prevNode][start] = 1;
    for (int i = 0; i < N; i++) {
        if(graph[start][i] == 1 && check[i] <= 1){
//            outGrpah[start][i] = 1;
            DFS(i);
        }
    }
}

int main(void){
    
    cin >> N;
    vector<int> node(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inp;
            graph[i][j] = inp;
            if(inp == 1) node[i] = j;
        }
    }

    for (int i = 0; i < N; i++) {
        DFS(i);
        for (int idx = 0; idx < N; idx++) {
            cout << check[idx] << ' ';
        }
        cout << '\n';
        memset(check, 0, sizeof(int) * N);
    }
    
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout << outGrpah[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    
    return 0;
}
