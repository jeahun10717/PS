#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int T, N, M;
char inp;
char A[101][101];
char B[101][101];

void spin(int N){
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            B[y][x] = A[N - 1 - x][y];
        }
    }
}

void slide(int N){
    int dotCnt = 0, notDotIdx = 0;
    for (int y = 0; y < N; y++) {
        for (int x = N - 1; x >= 0; x--) {
            if(B[y][x] == '.'){
                dotCnt++;
                continue;
            }
        }
        for (int x = N - 1; x >= 0; x--) {
            if(B[y][x] != '.'){
                notDotIdx = x;
                break;
            }
        }
        for (int x = N - 1; x >= dotCnt; x--) {
            A[y][x] = B[y][notDotIdx];
            notDotIdx--;
        }
        for (int x = dotCnt - 1; x >= 0; x--) {
            A[y][x] = '.';
        }
    }
}

void spinAndSlide(int N){
    spin(N);
    slide(N);
}

int main(void){
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> inp;
                A[y][x] = inp;
            }
        }
        for (int roop = 0; roop < M; roop++) {
            spinAndSlide(N);
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cout << A[y][x];
            }
            cout << '\n';
        }
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
    }
  
    
    return 0;
}
