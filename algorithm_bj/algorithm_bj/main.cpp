#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <queue>

#define lld long long int

using namespace std;

char type, inp;
int cmdIdx;
string inpStr;
int R, C;
char inpArr[210][210];
char DtoBArr[210][210];

string output(int inp){
    string outStr = to_string(inp);
    if(outStr.size() == 1){
        return "  " + outStr;
    }else if(outStr.size() == 2){
        return " " + outStr;
    }else{
        return outStr;
    }
}

void BtoD(int rowRan, int colRan, int stRow, int stCol, string &result){
    
//    if(rowRan == 1 && colRan == 1){
//        result+=inpArr[stRow][stCol];
//        return;
//    }
//    if(rowRan == 1 && colRan == 1){
//        result += inpArr[stRow][stCol];
//        return;
//    }
    
    char bitChk = inpArr[stRow][stCol];
    bool breakFlag = false;
    for (int i = stRow; !breakFlag && i < stRow + rowRan; i++) {
        for (int j = stCol; !breakFlag && j < stCol + colRan; j++) {
//            if(i < R && j < C){
                if(bitChk != inpArr[i][j]) {
                    breakFlag = true;
                    break;
                }
//            }
        }
    }
    
    if(breakFlag == true){ // 하나라도 다른 비트가 존재할 때
        result += 'D'; // divide 해 주고
//        int preRow = (rowRan / 2 + rowRan % 2);
//        int preCol = (colRan / 2 + colRan % 2);
        int nxRowRan = rowRan / 2 + rowRan % 2;
        int nxColRan = colRan / 2 + colRan % 2;
//        rowRan = rowRan - nxRowRan;
//        colRan = colRan - nxColRan;
        BtoD(nxRowRan, nxColRan, stRow, stCol, result);
        
//        if(stCol + nxColRan <= colRan)
        if(colRan - nxColRan != 0)
            BtoD(nxRowRan, colRan - nxColRan, stRow, stCol + nxColRan, result);
        
//        if(stRow + nxRowRan <= rowRan)
        if(rowRan - nxRowRan != 0)
            BtoD(rowRan - nxRowRan, nxColRan, stRow + nxRowRan, stCol, result);
        
//        if(stCol + nxColRan <= colRan && stRow + nxRowRan <= rowRan)
        if(rowRan - nxRowRan != 0 && colRan - nxColRan != 0)
            BtoD(rowRan - nxRowRan, colRan - nxColRan, stRow + nxRowRan, stCol + nxColRan, result);
        
        
    }else{ // 모든 비트가 같을 때
        result += inpArr[stRow][stCol];
    }
}

void DtoB(int rowRan, int colRan, int stRow, int stCol, string &inpStr){
    if(cmdIdx == inpStr.size()) return;
    if(inpStr[cmdIdx] == '1' || inpStr[cmdIdx] == '0'){
        for (int y = stRow; y < stRow + rowRan; y++) {
            for (int x = stCol; x < stCol + colRan; x++) {
                DtoBArr[y][x] = inpStr[cmdIdx];
            }
        }
        cmdIdx++;
        return;
    }
    if(inpStr[cmdIdx] == 'D'){
//        cmdIdx++;
        int nxRowRan = rowRan / 2 + rowRan % 2;
        int nxColRan = colRan / 2 + colRan % 2;
       
        cmdIdx++;
        DtoB(nxRowRan, nxColRan, stRow, stCol, inpStr);
        
//        if(stCol + nxColRan <= colRan)
        if(colRan - nxColRan != 0){
//            cmdIdx++;
            DtoB(nxRowRan, colRan - nxColRan, stRow, stCol + nxColRan, inpStr);
        }
        if(rowRan - nxRowRan != 0){
            DtoB(rowRan - nxRowRan, nxColRan, stRow + nxRowRan, stCol, inpStr);
        }
    
        if(rowRan - nxRowRan != 0 && colRan - nxColRan != 0){
            DtoB(rowRan - nxRowRan, colRan - nxColRan, stRow + nxRowRan, stCol + nxColRan, inpStr);
        }
        
    }
    
}

int main(void){

    freopen("bitmap.inp", "r", stdin);
    freopen("bitmap.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> type;
        if(type == '#') break;
        if(type == 'B'){
            cin >> R >> C;
            string result = "";
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cin >> inp;
                    inpArr[i][j] = inp;
                }
            }
            BtoD(R, C, 0, 0, result);
            cout << "D ";
            cout << output(R) << ' ' << output(C) << '\n';
//            for (int coutCnt = 0; coutCnt < result.size(); coutCnt++) {
//                cout << result[coutCnt];
//                if(coutCnt % 49 == 0 && coutCnt != 0) cout << '\n';
//            }
//            if(result.size() <= 49) cout << '\n';
            for (int coutCnt = 1; coutCnt < result.size() + 1; coutCnt++) {
                cout << result[coutCnt - 1];
                if(coutCnt % 50 == 0 && coutCnt != result.size()) cout << '\n';
            }
        }else if(type == 'D'){
            cin >> R >> C;
            string dStr = "";
            while (true) {
                cin >> inpStr;
                if(inpStr.size() == 50){
                    dStr += inpStr;
                    continue;
                }else{
                    dStr += inpStr;
                    break;
                }
            }
            cmdIdx = 0;
            DtoB(R, C, 0, 0, dStr);
            cout << "B ";
            cout << output(R) << ' ' << output(C) << '\n';
            int coutCnt = 0;
            string test = "";
            for (int y = 0; y < R; y++) {
                for (int x = 0; x < C; x++) {
                    test += DtoBArr[y][x];
                }
            }
            for (int coutCnt = 1; coutCnt < test.size() + 1; coutCnt++) {
                cout << test[coutCnt - 1];
                if(coutCnt % 50 == 0 && coutCnt != test.size()) cout << '\n';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
