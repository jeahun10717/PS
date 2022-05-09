#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <typeinfo>

using namespace std;

unsigned long long int n;

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;
    unsigned long long int maxWeight = 0;
//    long long int roop = 0;
    for (unsigned long long int i = 1; ; i++) {
        unsigned long long int powNum = 1;
        for (unsigned long long int j = 0; j < i+1; j++) {
            powNum *= 2;
        }
        maxWeight = (i + 1) * (powNum - 1) + i;
        if(maxWeight >= n) {
            cout << i << '\n';
            return 0;
        }
    }
    
    return 0;
}
