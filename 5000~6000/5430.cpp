#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int T, cmdCnt, inp;
string cmd, inpNum;

int AC(deque<int>& dq, string& cmd) {
    int direc = 0; // 0 은 순방향 1 은 역방향;
    for (int i = 0; i < cmd.size(); i++) {
        if(cmd[i] == 'R'){
            direc = !direc;
        }else if(cmd[i] == 'D'){
            if(dq.empty()) return -1; // dq 가 비어 있는데 D 가 들어와서 지우려고 할 때
            else{
                if(direc == 0){ // 순방향
                    dq.pop_front();
                }else{ // 역방향
                    dq.pop_back();
                }
            }
        }
    }
    return direc;
}

int main(void) {
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        deque<int> dq;
        cin >> cmd >> cmdCnt;
        char c; string str = "";
        for (int j = 0;; j++)
        {
            cin >> c;
            if(cmdCnt == 0) {
                cin >> c;
                break;
            };
            if (isdigit(c)) {
                str += c;
            }
            else {
                if (c == ',') {
                    dq.push_back(stoi(str));
                    str = "";
                }else if(c == ']') {
                    dq.push_back(stoi(str));
                    str = "";
                    break;
                }
            }
        }
        int retAC = AC(dq, cmd);
        if(retAC == 0){  // AC return 은 -1 은 error 0 은 순방향, 1 은 역방향
            cout << '[';
            for (int dqIdx = 0; dqIdx < (int)dq.size() - 1; dqIdx++) {
                cout << dq[dqIdx] << ',';
            }
            if(dq.size()){
                cout << dq.back();
            }
            cout << "]\n";
        }
        else if(retAC == 1){
            cout << '[';
            for (int dqIdx = (int)dq.size() - 1; dqIdx > 0; dqIdx--) {
                cout << dq[dqIdx] << ',';
            }
            if(dq.size()){
                cout << dq.front();
            }
            cout << "]\n";
        }
        else { // error 검출
            cout << "error" << '\n';
        }
        
    }
    
    return 0;
}
