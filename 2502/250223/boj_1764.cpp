//1764 듣보잡

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    unordered_map<string, int> um;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        um[s]++;
    }
    vector<string> ans;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (um[s] > 0) {
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
