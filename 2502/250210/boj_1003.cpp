//1003 피보나치 함수

#include <iostream>

using namespace std;

int meno[41][2] = {0,};

void fibonacci(int n, int& zero, int& one) {
    if (n == 0) {
        meno[n][0] = 1;
        meno[n][1] = 0;
    } else if (n == 1) {
        meno[n][0] = 0;
        meno[n][1] = 1;
    } else {
        if (meno[n][0] == 0 && meno[n][1] == 0) {
            fibonacci(n-1, zero, one);
            fibonacci(n-2, zero, one);
        }
        meno[n][0] = meno[n-1][0] + meno[n-2][0];
        meno[n][1] = meno[n-1][1] + meno[n-2][1];
    }
    zero = meno[n][0];  
    one = meno[n][1];
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int zero = 0, one = 0;
        fibonacci(N, zero, one);
        cout << zero << " " << one << "\n";
    }

}