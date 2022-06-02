#include <iostream>
#include <math.h>

using namespace std;

int N, r, c, result;
//int zArr[33000][33000];
int z0, z1, z2, z3;

void zRec(int startR, int startC, int N, int startVal, int r, int c){
//    if( N == 2 ){
//        if(startR == r && startC == c) {
//            result = startVal;
//            return;
//        }
//        else if(startR == r && startC + 1 == c) {
//            result = startVal + 1;
//            return;
//        }
//        else if(startR + 1 == r && startC == c) {
//            result = startVal + 2;
//            return;
//        }
//        else if(startR + 1 == r && startC + 1 == c) {
//            result = startVal + 3;
//            return;
//        }
//    }
    if(r >= startR && c >= startC && r <= N/2 - 1 + startR && c <= N/2 - 1 + startC){
        
        if(startR == r && startC == c) {
            result = startVal;
            return;
        }
        zRec(startR, startC, N / 2, startVal, r, c);
        
    }else if(r >= startR && c >= N / 2 + startC && r <= N/2 - 1 + startR && c <= N - 1 + startC){
        
        if(startR == r && startC + N / 2 == c) {
            result = startVal + (N/2) * (N/2);
            return;
        }
        zRec(startR, startC + N / 2, N / 2, startVal + (N/2) * (N/2), r, c);
        
    }else if(r >= N / 2 + startR && c >= startC && r <= N - 1 + startR && c <= N / 2 - 1 + startC){
        
        if(startR + N / 2 == r && startC == c) {
            result = startVal + 2 * (N/2) * (N/2);
            return;
        }
        zRec(startR + N / 2, startC, N / 2, startVal + 2 * (N/2) * (N/2), r, c);
        
    }else if(r >= N / 2 + startR && c >= N / 2 + startC && r <= N - 1 + startR && c <= N - 1 + startC){
        
        if(startR + N / 2 == r && startC + N / 2 == c) {
            result = startVal + 3 * (N/2) * (N/2);
            return;
        }
        zRec(startR + N / 2, startC + N / 2, N / 2, startVal + 3 * (N/2) * (N/2), r, c);
        
    }else return;
}


int main(void){
    
    cin >> N >> r >> c;
    
    zRec(0, 0, (int)pow(2, N), 0, r, c);
    
    cout << result << '\n';
    
    
    return 0;
}
