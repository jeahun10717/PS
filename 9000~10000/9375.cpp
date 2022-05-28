#include <iostream>
#include <string>
#include <map>

using namespace std;

int T, n;
string cltName;
string cltType;

map<string, string> m;
map<string, int> cntMap;

int main(void) {

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> cltName >> cltType;
            m.insert(make_pair(cltName, cltType));
            if (cntMap.count(cltType) == 0) {
                cntMap.insert(make_pair(cltType, 1));
            }
            else {
                cntMap.at(cltType)++;
                  
                //cntMap[cltName] = cntMap[cltName] + 1;
            }
        }
        int result = 1;
        for (auto mapRoop = cntMap.begin(); mapRoop != cntMap.end(); mapRoop++) {
            result *= ((mapRoop->second) + 1);
        }
        cout << result - 1 << '\n';
        m.clear();
        cntMap.clear();
    }



    return 0;
}
