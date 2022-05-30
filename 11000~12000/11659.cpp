#include <iostream>
#include <vector>

using namespace std;

int N, M, inp, inp1, inp2;
vector<int> inpVec;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        if(i==0) inpVec.push_back(inp);
        else inpVec.push_back(inpVec[i-1] + inp);
    }
    
    for (int i = 0; i < M; i++) {
        cin >> inp1 >> inp2;
        if(inp1 == 1) cout << inpVec[inp2 - 1] << '\n';
        else cout << inpVec[inp2 - 1] - inpVec[inp1 - 2] << '\n';
    }
    
    return 0;
}
