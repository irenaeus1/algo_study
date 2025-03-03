//9095번 1, 2, 3 더하기

#include <iostream>

using namespace std;

int dp[11];

int main() {
    int t;
    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 10; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
