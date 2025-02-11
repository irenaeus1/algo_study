//21631 Checkers

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    long long a, b;  // 범위가 10^18까지이므로 long long 사용
    cin >> a >> b;

    cout << min(a + 1, b);  // 흰색 조각 + 1과 검은색 조각 수 중 작은 값 출력
}