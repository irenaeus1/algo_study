#include <iostream>
using namespace std;

int main(){
    string input;
    while (true){
        cin >> input;
        if (input == "0") break;
        bool is_palindrome = true;
        for (int i = 0; i < input.length()/2; i++){
            if (input[i] != input[input.length()-i-1]){
                is_palindrome = false;
                break;
            }
        }
        cout << (is_palindrome?"yes":"no") << '\n';
    }
    return 0;
}