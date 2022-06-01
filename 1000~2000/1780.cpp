#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int paper[2188][2188];
int N, inp;
int cntOne, cntMOne, cntZero;

void recPaperChk (int startRow, int startCol, int N){
    int paperChk = paper[startRow][startCol];
    bool isAllSame = true;
    for (int i = startRow; isAllSame && i < N + startRow; i++) {
        for (int j = startCol; isAllSame && j < N + startCol; j++) {
            if(paperChk != paper[i][j]){
                isAllSame = false;
                break;
            }
        }
    }
    if(isAllSame == true){ // 2중 for 문을 돌았을 때 전부 같은 종이일 때
        if(paperChk == -1) cntMOne++;
        else if(paperChk == 0) cntZero++;
        else if(paperChk == 1) cntOne++;
    }else{
        recPaperChk(startRow, startCol, N/3); recPaperChk(startRow, startCol + N/3, N/3); recPaperChk(startRow, startCol + 2 * N / 3, N/3);
        recPaperChk(startRow + N/3, startCol, N/3); recPaperChk(startRow + N/3, startCol + N/3, N/3); recPaperChk(startRow + N/3, startCol + 2 * N / 3, N/3);
        recPaperChk(startRow + 2 * N / 3, startCol, N/3); recPaperChk(startRow + 2 * N / 3, startCol + N/3, N/3); recPaperChk(startRow + 2 * N / 3, startCol + 2 * N / 3, N/3);
    }
    
    
}

int main(void){
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inp;
            paper[i][j] = inp;
        }
    }
    
    recPaperChk(0, 0, N);
    cout << cntMOne << '\n' << cntZero << '\n' << cntOne << '\n';

    return 0;
}
