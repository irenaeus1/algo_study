#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    if (a.length() == b.length()) return a < b;//길이가 같으면 사전순으로 정렬
    return a.length() < b.length();//길이가 다르면 길이순으로 정렬
}

int main(){
    int N;
    cin >> N;
    string *arr = new string[N];
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N, compare);
    for (int i = 0; i < N; i++){
        if (i > 0 && arr[i] == arr[i-1]) continue;
        cout << arr[i] << '\n';
    }
    delete[] arr;
    return 0;
}
