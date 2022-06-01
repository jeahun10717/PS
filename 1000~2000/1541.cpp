#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int num;
char oper;
vector<int> toMinusVec;

int main(void){
    
    cin >> num;
    toMinusVec.push_back(num);
    while (true) {
        
        cin >> oper; cin >> num;
        if(cin.eof()) {
            break;
        }
        if(num == 0) break;
//        cout << oper << "!!!!!!!!!!!!" << num << "@@@@@@@@@@@@" << '\n';
        if(oper == '+'){
            toMinusVec[toMinusVec.size() - 1] += num;
        }else if(oper == '-'){
            toMinusVec.push_back(num);
        }
        
    }
    
    int result = toMinusVec[0];
    for (int i = 1; i < toMinusVec.size(); i++) {
        result -= toMinusVec[i];
    }
    
    cout << result << '\n';
    
    return 0;
}
