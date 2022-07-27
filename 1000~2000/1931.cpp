#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, startInp, endInp;
vector<pair<int, int>> semTimeVec;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second){ // 끝지점이 같을 때
        return a.first <= b.first; // 시작지점이 큰 순으로 정렬
    }else{
        return a.second < b.second;
    }
}

int main(void){
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> startInp >> endInp;
        semTimeVec.push_back(make_pair(startInp, endInp));
    }
    
    sort(semTimeVec.begin(), semTimeVec.end(), compare);
    
    int semEnd = semTimeVec[0].second;
    int semCnt = 1;

    for (int i = 1; i < semTimeVec.size(); i++) {
        if(semEnd > semTimeVec[i].first) { // 앞의 회의시간의 끝시간이 뒤의 회의시간의 시작시간보다 크면 뒤의 회의는 추가불가
            continue;
        }else{
            semEnd = semTimeVec[i].second;
            semCnt++;
        }
    }
    
    cout << semCnt << '\n';
    
    return 0;
}
