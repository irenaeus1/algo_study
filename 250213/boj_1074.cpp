// 1074번: Z

#include <iostream>

using namespace std;

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    
    int size = (1 << N);
    int result = 0;

    while (N > 0) {
        int half = size / 2;
        if (r < half && c < half) {
            // 왼쪽 위
        } else if (r < half && c >= half) {
            // 오른쪽 위
            result += half * half;
            c -= half;
        } else if (r >= half && c < half) {
            // 왼쪽 아래
            result += 2 * half * half;
            r -= half;
        } else {
            // 오른쪽 아래
            result += 3 * half * half;
            r -= half;
            c -= half;
        }
        size = half;
        N--;
    }
    cout << result << endl;
    return 0;
}
