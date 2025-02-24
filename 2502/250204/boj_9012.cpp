#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() 
{
    int testCaseCount;
    cin >> testCaseCount;
    
    while (testCaseCount--) 
    {
        string parentheses;
        cin >> parentheses;
        
        stack<char> parenthesisStack;
        bool isValid = true;
        
        for (char currentChar : parentheses) 
        {
            if (currentChar == '(') 
            {
                parenthesisStack.push(currentChar);
            }
            else 
            {
                if (parenthesisStack.empty()) 
                {
                    isValid = false;
                    break;
                }
                parenthesisStack.pop();
            }
        }
        
        if (parenthesisStack.empty() && isValid) 
        {
            cout << "YES\n";
        }
        else 
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}