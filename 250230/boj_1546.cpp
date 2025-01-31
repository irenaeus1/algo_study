#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    int max_input = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (max_input < arr[i]) {
            max_input = arr[i];
        }
    }
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += double(arr[i]) / max_input * 100;
    }
    cout << sum / n << endl;
    return 0;
}