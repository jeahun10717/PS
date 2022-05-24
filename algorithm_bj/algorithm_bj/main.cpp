#include <iostream>
#include <cmath>

using namespace std;

int T;
int x1;
int y3;
int r1;
int x2;
int y2;
int r2;

int Abs(int x) {
    return (int)abs(x);
}

int Pow(int x) {
    return (int)pow(x, 2);
}

int main(void) {
    cin >> T;
    while(T--) {
        int ans = 0;
        cin >> x1 >> y3 >> r1 >> x2 >> y2 >>r2;

        if (x1 == x2 && y3 == y2 && r1 == r2) ans = -1;

        if(Abs(x1 + r1) > Abs(x2 + r2) && Abs(x1 - r1) > Abs(x2 - r2) && Abs(y3 + r1) > Abs(y2 + r2) && Abs(y3 - r1) > Abs(y2 - r2)) ans = 0;
        else if(Abs(x1 + r1) < Abs(x2 + r2) && Abs(x1 - r1) < Abs(x2 - r2) && Abs(y3 + r1) < Abs(y2 + r2) && Abs(y3 - r1) < Abs(y2 - r2)) ans = 0;
        else if(Abs(x1 + r1) == Abs(x2 + r2) || Abs(x1 - r1) == Abs(x2 - r2) || Abs(y3 + r1) == Abs(y2 + r2) || Abs(y3 - r1) == Abs(y2 - r2))) ans = 1;

        if(Pow(x2 - x1) + Pow(y2 - y3) == Pow(r1 + r2)) ans = 1;
        else if(Pow(x2 - x1) + Pow(y2 - y3) < Pow(r1 + r2)) ans = 2;
        else if(Pow(x2 - x1) + Pow(y2 - y3) > Pow(r1 + r2)) ans = 0;

        cout << ans << '\n';
    }
}
