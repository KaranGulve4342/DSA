// GFG

//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }
    
    // Function to convert an infix expression to a postfix expression
    string infixToPostfix(string s) {
        stack<char> opStack;
        string result;
        
        for (char ch : s) {
            // If the character is an operand, add it to the result
            if (isalnum(ch)) {
                result += ch;
            }
            // If the character is '(', push it to the stack
            else if (ch == '(') {
                opStack.push(ch);
            }
            // If the character is ')', pop and output from the stack until '(' is encountered
            else if (ch == ')') {
                while (!opStack.empty() && opStack.top() != '(') {
                    result += opStack.top();
                    opStack.pop();
                }
                opStack.pop(); // pop '('
            }
            // An operator is encountered
            else {
                while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch)) {
                    result += opStack.top();
                    opStack.pop();
                }
                opStack.push(ch);
            }
        }
        
        // Pop all the operators from the stack
        while (!opStack.empty()) {
            result += opStack.top();
            opStack.pop();
        }
        
        return result;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends