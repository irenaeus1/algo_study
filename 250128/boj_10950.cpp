#include <iostream>
#include <queue> 
using namespace std;

int main(void) {

    int n;
    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        q.push(a + b);
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}