// Reverse a String Using Stack
/*
#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "Gabbar";

    stack<char> s;

    for(int i = 0;i < str.length();i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}
*/

// Deleting the middle element
/*
void solve(stack<int>&inputStack, int count,int size){
    // base case
    if(count == size/2){
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // RECURSIVE CALL
    solve(inputStack,count+1,size)
}
*/

// Valid Parentheses
/*
bool isValidParenthesis(string expression){
    stack<char>s;
    for(int i = 0;i < expression.length();i++){
        char ch = expression[i];

        // if opening bracket, stack push
        // if close bracket, stacktop check and pop

        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{
            // for closing bracket
            if(!s.empty()){
                char top = s.top();
                if((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}
*/

// Insert an element At its Bottom in A Given Stack
/*
void solve(stack<int>& s,int x){
    // base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve(s, x);

    s.push(num);
}
*/

// Reverse stack using recursion
/*
void insertAtBottom(stack<int> &stack){
    // basecase
    if(s.empty()){
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack){
    // base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(num);
}

*/

// sort a Stack
/*
void sortedInsert(stack<int> &stack, int num){
    // base case
    if(s.empty() || (!s.empty() && s.top()<num){
        s.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    // recusive call
    sortedInsert(stack,num);
    stack.push(n);
}
void sortedStack(stack<int> &stack){
    // base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    sortedInsert(stack,num);

}



*/

// Redundant Brackets
/*
#include<stack>
bool findRedundantBrackets(string &s){
    stack<char>st;
    for(int i = 0;i < s.length(),i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else
        {
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
}

*/

// minimum cost to make string valid
/*
#include<stack>
int findMinimumCost(string str)
{
    // odd condition
    if(str.length()%2 == 1){
        return -1;
    }
    stack<char>s;
    for(int i = 0;i < str.length();i++){
        char ch = str[i];

        if(ch == '{'){
            s.push(ch);
        }
        else{
            // ch is closed brace
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }

    // stack contains invalid expression
    int a = 0,b = 0;
    while(!s.empty()){
        if(s.top() == '{'){
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }
    int ans = (a + 1)/2 + (b + 1)/2;
    return ans;
    
}
*/

// Next Smaller Element
/*
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans;

    for(int i = n - 1;i >= 0;i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
*/

// Largest Rectangle in histogram
/*
vector<int> nextSmallerElement(vector<int> arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1;i >= 0;i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0;i < n;i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights){
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    for(int i = 0;i < n;i++){
        int l = heights[i];

        if(next[i] == -1){
            next[i] = n;
        }
        
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

*/