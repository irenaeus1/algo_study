//1271 엄청난 부자2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 큰 수의 나눗셈과 나머지 연산을 한 번에 수행 (n을 m으로 나눈 몫과 나머지)
pair<string, string> divideAndModulo(string n, string m) {
    // m이 n보다 크면 몫은 0, 나머지는 n
    if (n.length() < m.length() || (n.length() == m.length() && n < m)) {
        return {"0", n};
    }
    
    string quotient;
    string temp;
    
    for (int i = 0; i < n.length(); i++) {
        temp += n[i];
        
        // 앞의 0 제거
        while (temp.length() > 1 && temp[0] == '0') {
            temp = temp.substr(1);
        }
        
        // temp가 m보다 작으면 다음 자리 수로 넘어감
        if (temp.length() < m.length() || (temp.length() == m.length() && temp < m)) {
            if (!quotient.empty()) {
                quotient += '0';
            }
            continue;
        }
        
        // temp를 m으로 나눌 수 있는 최대 횟수 계산
        int count = 0;
        string subtractTemp = temp;
        
        while (subtractTemp.length() > m.length() || (subtractTemp.length() == m.length() && subtractTemp >= m)) {
            // m을 subtractTemp에서 뺌
            int borrow = 0;
            string diff;
            
            for (int j = subtractTemp.length() - 1, k = m.length() - 1; j >= 0; j--, k--) {
                int subtractValue = (subtractTemp[j] - '0') - (k >= 0 ? (m[k] - '0') : 0) - borrow;
                
                if (subtractValue < 0) {
                    subtractValue += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                
                diff = char(subtractValue + '0') + diff;
            }
            
            // 앞의 0 제거
            while (diff.length() > 1 && diff[0] == '0') {
                diff = diff.substr(1);
            }
            
            subtractTemp = diff;
            count++;
        }
        
        quotient += to_string(count);
        temp = subtractTemp;
    }
    
    // 앞의 0 제거
    while (quotient.length() > 1 && quotient[0] == '0') {
        quotient = quotient.substr(1);
    }
    
    return {quotient.empty() ? "0" : quotient, temp.empty() ? "0" : temp};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string n, m;
    cin >> n >> m;

    auto [quotient, remainder] = divideAndModulo(n, m);
    cout << quotient << '\n' << remainder << '\n';
    return 0;
}