#include <iostream>
#include <queue> 
using namespace std;

int main(void) {
    queue<int> q;

    //eol 입력 받을 때까지 반복

    while (true) {
        int a, b;
        cin >> a >> b;
        if (cin.eof()) break;
        q.push(a + b);
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}