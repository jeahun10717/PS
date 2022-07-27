#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, patCnt;
string pat, inp;

void makeTable(string& pat, vector<int>& table){
    int j = 0;
    for (int i = 1; i < pat.size(); i++) {
        while (j > 0 && pat[i] != pat[j]) {
            j = table[j-1];
        }
        if(pat[i] == pat[j]){
            j++;
            table[i] = j;
        }
    }
}

void KMP(string& pat, string& inp, vector<int>& table){
    int j = 0;
    for (int i = 0; i < inp.size(); i++) {
        while (j > 0 && inp[i] != pat[j]) {
            j = table[j - 1];
        }
        if(inp[i] == pat[j]){
            if(j == pat.size() - 1){
                // i 와 j 가 일치하고 패턴의 index 를 나타내는 j 가 끝까지 일치하면
                // inp 문자열에서 pattern 과 완전히 일치하는 부분을 찾은 것이다
                patCnt++; // 패턴의 개수 올려주기
                j = table[j];
            }else{
                j++;
            }
        }
    }
}


int main(void){
    
    cin >> N >> M >> inp;
    
    pat = "I";
    for (int i = 0; i < N; i++) pat+="OI";
//
//    pat = "abacaaba";
//    inp = "ababacabacaabacaaba";
    vector<int> table(pat.size(), 0);
    
    makeTable(pat, table);
    KMP(pat, inp, table);
    
    cout << patCnt << '\n';
    
    return 0;
}
