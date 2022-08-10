#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int T, A, B;
int check[10001]; // <다음 노드의 경로를 저장, DSLR 을 저장>

int dir(int type, int inp){
    if(type == 0) return inp * 2 % 10000;
    else if(type == 1) return (10000 + (inp - 1)) % 10000;
    else if(type == 2) return inp * 10 + inp / 1000 - (inp / 1000) * 10000;
    else return (inp + (inp % 10) * 10000) / 10;
}

char DSLR_judge(int inp){
    if(inp == 0) return 'D';
    else if(inp == 1) return 'S';
    else if(inp == 2) return 'L';
    else return 'R';
}

string BFS(int start, int end){
    queue<tuple<int, string>> tq;
    tq.push({start, ""});
    check[start] = 1;
    while (!tq.empty()) {
        int qFrontNode = get<0>(tq.front());
        string qFrontStr = get<1>(tq.front());
        tq.pop();
        for (int i = 0; i < 4; i++) {
            int next = dir(i, qFrontNode);
            if(check[next] == 0){ // 방문하지 않은 노드일 때
                check[next] = 1;
                tq.push({next, qFrontStr + DSLR_judge(i)});
                if(next == end) return qFrontStr + DSLR_judge(i);
            }
        }
    }
    return "error";
}

int main(void){

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        memset(check, 0, sizeof(check));
        cout << BFS(A, B) << '\n';

    }
//    for (int i = 0; i < 4; i++) {
//        cout << dir(i, T) << '\n';
//    }
//
//    cout << -1 % 29;

    return 0;
}
