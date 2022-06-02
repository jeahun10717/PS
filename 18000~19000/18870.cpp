#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v1, v2, v3;
int N, inp;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        v1.push_back(inp);
        v2.push_back(inp);
    }
    
    sort(v2.begin(), v2.end());
    
    v3.push_back(v2[0]);
    for (int i = 1; i < v2.size(); i++) {
        if(v2[i-1] != v2[i]) v3.push_back(v2[i]);
    }
    
    int roop = 0;
    
    
    for (int i = 0; i < v1.size(); i++) {
        cout << lower_bound(v3.begin(), v3.end(), v1[i]) - v3.begin() << " ";
    }
    
    return 0;
}
