#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     unordered_map<int, int> a;
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         a[x] = 1;
//     }
//     int m;
//     cin >> m;
//     for (int i = 0; i < m; i++) {
//         int x;
//         cin >> x;
//         cout << a[x] << '\n';
//     }
//     return 0;
// }
//rewrite using binary search   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << binary_search(a.begin(), a.end(), x) << '\n';
    }
}
