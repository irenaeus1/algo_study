//1931번 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int end = 0;
    for(int i = 0; i < n; i++) {
        if(v[i].second >= end) {
            end = v[i].first;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
