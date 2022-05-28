#include <iostream>

using namespace std;

int N, inp, cnt;
int inpArr[129][129];
int blueCnt, whiteCnt;

void paper(int N, int colStart, int rowStart){
    bool sameClrFlag = true;
    bool roopOutFlag = false;
    int color = inpArr[rowStart][colStart]; // 1 일때 blue 0 일때 white
    for (int i = rowStart; !roopOutFlag && i < N + rowStart; i++) {
        for (int j = colStart; !roopOutFlag && j < N + colStart; j++) {
            if(color == inpArr[i][j]){ // 색이 같을 때
                continue;
            }else{ // 색이 하나라도 다를 때
                sameClrFlag = false;
                roopOutFlag = true;
                break;
            }
        }
    }
    if(sameClrFlag == true){ // 모든 색이 같을 때
        if(color == 1) blueCnt++;
        else whiteCnt++;
    }else{ // 다른 색이 존재할 떄 --> 재귀 타고 들어가야 함
        paper(N/2, colStart, rowStart);
        paper(N/2, colStart + N/2, rowStart);
        paper(N/2, colStart, rowStart + N/2);
        paper(N/2, colStart + N/2, rowStart + N/2);
    }
}

int main(void){
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inp;
            inpArr[i][j] = inp;
        }
    }
    
    paper(N, 0, 0);
    
    cout << whiteCnt << '\n' << blueCnt << '\n';
    
    return 0;
}
