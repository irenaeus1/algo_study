#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    
    int max_sum = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                if (sum == M) {  // 정확한 합을 찾으면 즉시 반환
                    cout << M << '\n';
                    return 0;
                }
                if (sum < M && sum > max_sum) {
                    max_sum = sum;
                }
            }
        }
    }
    cout << max_sum << '\n';
    return 0;
}