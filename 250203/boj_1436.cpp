#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int count = 0;
    int num = 666;

    while (count < N) {
        string str = to_string(num);
        if (str.find("666") != string::npos) {
            count++;
        }
        num++;
    }

    cout << num - 1;
    return 0;
}

