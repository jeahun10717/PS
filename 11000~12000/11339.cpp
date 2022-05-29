#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, inp;
vector<int> ATM;

int main(void){
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> inp;
        ATM.push_back(inp);
    }
    
    int result = 0;
    sort(ATM.begin(), ATM.end(), greater<>());
    for (int i = 0; i < ATM.size(); i++) {
        result += (ATM[i] * (i + 1));
    }
    
    cout << result << '\n';
    return 0;
}
