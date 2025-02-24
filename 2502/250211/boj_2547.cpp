//2547 사탕선생 고창영

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        long long sum = 0;
        for(int j = 0; j < n; j++) {
            long long candy;
            cin >> candy;
            sum = (sum + candy % n) % n;
        }
        if(sum == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
