// GFG

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;
        stringstream ss;
        int n = exp.length();
        
        for (int i = 0; i < n; i++) {
            if (isalpha(exp[i])) {
                // If the character is an operand, push it as a string to the stack
                st.push(string(1, exp[i]));
            } else {
                // If the character is an operator, pop two operands from the stack
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                
                // Form the infix expression with parentheses
                ss << "(" << op2 << exp[i] << op1 << ")";
                
                // Push the resulting expression back to the stack
                st.push(ss.str());
                ss.str("");
            }
        }
        
        // The final element of the stack is the infix expression
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends