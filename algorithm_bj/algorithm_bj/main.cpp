#include <cmath>
#include <iostream>

using namespace std;

long long int a, b, c, d, u;
int totalCnt;
long long int aCnt, gCnt;

long long int POW(long long int a, long long int x){
    long long int result = 1;
    for (int i = 0; i < x; i++) {
        result *= a;
    }
    return result;
}

int main(void){
    
    cin >> a >> b >> c >> d >> u;
    
    if((u - a) / b >= 0){
        if((u - a) >= 0) aCnt = ((u - a) / b) + 1;
    }
    
    if(d == 1 && c <= u){
        gCnt++;
        if(c - a >= 0 && (c - a) % b == 0) totalCnt--;
    }
    else if(d > 1){
        long long int gnum;
        for (int i = 0;; i++) {
            gnum = (c * POW(d, i));
            if(gnum > u) break;
            else {
                if(u / c >= 1){
                    if(gnum - a >= 0 && (gnum - a) % b == 0) totalCnt--;
                    gCnt++;
                }
                
            }
        }
    }
    
    cout << totalCnt + gCnt + aCnt << '\n';
    
    return 0;
}
