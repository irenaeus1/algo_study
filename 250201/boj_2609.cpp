#include <iostream>

using namespace std;

int calculateGCD(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int gcd = calculateGCD(a, b);

    cout << gcd << '\n';
    cout << a * b / gcd << '\n';

    return 0;
}

int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}