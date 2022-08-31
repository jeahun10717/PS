#include <iostream>
#include <vector>

using namespace std;

int T, M, N, x, y;

int GCD(int a, int b){
    if(a % b == 0) return b;
    return GCD(b, a % b);
}
int LCM(int a, int b){
    return (a * b) / GCD(a, b);
}

int main(void){
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;
        int dtryYear = LCM(M, N);
        int k = x;
        while (true) {
            if((k - x) % M == 0 && (k - y) % N == 0) break;
            if( k > dtryYear ){
                k = -1;
                break;
            }
            k += M;
        }
        cout << k << '\n';
    }
    
    
    return 0;
}
