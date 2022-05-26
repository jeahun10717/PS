#include <iostream>

using namespace std;

int T, x1, y1, x2, y2, n, cx, cy, r;


int imExCntFunc(int x1, int y1, int x2, int y2, int cx, int cy, int r){
    int inOutCnt = 0;
    int circle1 = (cx-x1)*(cx-x1) + (cy-y1)*(cy-y1);
    int circle2 = (cx-x2)*(cx-x2) + (cy-y2)*(cy-y2);
    if(circle1 < r * r && circle2 > r * r){
        inOutCnt++;
    }else if(circle1 > r * r && circle2 < r * r){
        inOutCnt++;
    }
    return inOutCnt;
}

int main (void){
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        int inOutCnt = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        for (int j = 0; j < n; j++) {
            cin >> cx >> cy >> r;
            inOutCnt+=imExCntFunc(x1, y1, x2, y2, cx, cy, r);
        }
        cout << inOutCnt << '\n';
    }
    
    
    return 0;
}
