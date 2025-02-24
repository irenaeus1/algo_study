//10828 스택

#include <iostream>
#include <stack>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    cin >> n;
    stack<int> s;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        else if(str == "pop") {
            if(s.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(str == "size") {
            cout << s.size() << "\n";
        }
        else if(str == "empty") {
            cout << s.empty() << "\n";
        }
        else if(str == "top") {
            if(s.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << s.top() << "\n";
            }
        }
    }
    return 0;
}