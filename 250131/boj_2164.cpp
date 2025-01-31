#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
    return 0;
}

//수학적 규칙성

// #include <iostream>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int n;
//     cin >> n;
    
//     if (n == 1) {
//         cout << 1;
//         return 0;
//     }
    
//     int power = 1;
//     while (power * 2 <= n) {
//         power *= 2;
//     }
    
//     int result = 2 * (n - power);
//     if (result == 0) result = power;
    
//     cout << result;
//     return 0;
// }