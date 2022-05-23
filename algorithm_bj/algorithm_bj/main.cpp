#include <iostream>
#include <algorithm>

using namespace std;

int T, x1, y1, r1, x2, y2, r2;

int chkCrossPoint(int x1, int y1, int r1, int x2, int y2, int r2){
    int maxRad = max(r1, r2);
    maxRad = maxRad*maxRad;
    int dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    if(x1 == x2 && y1 == y2 && r1 == r2){ // 무한개의 점이 나올 경우
        return -1;
    }
    if(maxRad > dist){
        if(dist < (r1 - r2) * (r1 - r2)){
            return 0;
        }else if(dist == (r1 - r2) * (r1 - r2)){
            return 1;
        }else if(dist > (r1 - r2) * (r1 - r2)){
            return 2;
        }
    }else if(maxRad < dist){
        if(dist > (r1 + r2) * (r1 + r2)){
            return 0;
        }else if(dist == (r1 + r2) * (r1 + r2)){
            return 1;
        }else if(dist < (r1 + r2) * (r1 + r2)){
            return 2;
        }
    }else if(maxRad == dist){
        return 2;
    }
    return -1;
}

int main() {
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << chkCrossPoint(x1, y1, r1, x2, y2, r2) << '\n';
    }
    
    
    return 0;
}
