#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num;
    cin >> num;

    int *numbers = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + num);

    for (int i = 0; i < num; i++) {
        cout << numbers[i] << '\n';
    }

    delete[] numbers;
    return 0;
}