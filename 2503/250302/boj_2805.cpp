//2805번 나무 자르기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> trees(n);
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }
    
    sort(trees.begin(), trees.end());

    int left = 0, right = trees.back();
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (trees[i] > mid) {
                sum += trees[i] - mid;
            }
        }

        if (sum >= m) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << '\n';

    return 0;
}

