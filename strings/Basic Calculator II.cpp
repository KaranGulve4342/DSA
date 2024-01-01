// LEETCODE 227

/*
int prio(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2; // *, /
}
string solve(string val1, string val2, char ch){
    int a = stoi(val1);
    int b = stoi(val2);
    int ans;
    if(ch == '+') ans = a+b;
    if(ch == '-') ans = a-b;
    if(ch == '*') ans = a*b;
    if(ch == '/') ans = a/b;
    string q = to_string(ans);
    return q;
}
bool isDigit(char ch){
    if(ch >= 48 && ch <= 57) return true;
    else return false;
}
int calculate(string s){
    string t = "";
    for(int i = 0;i < s.length();i++){
        if(s[i] != ' ') t.push_back(s[i]);
    }
    s = t;
    stack<int> val;
    stack<char> op;
    for(int i = 0;i < s.length();i++){
        // check if s[i] is digit (0-9)
        if(isDigit(s[i])){ // digit
            if(i == 0 || !isDigit(s[i-1])) val.push(to_string(s[i]));
            else{
                string q = val.top();
                val.pop();
                q.push_back(s[i]);
                val.push(q);
            }
        }
        else{ // s[i] it is -> *,/,+,-
            if(op.size() == 0) op.push(s[i]);
            else if(prio(s[i]) > prio(op.top())) o.push(s[i]);
            else{
                // priority(s[i]) <= priority(op.top())
                while(op.size() > 0 && prio(s[i]) <= prio(op.top())){
                    // i have to do val1 op val2
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }       
        }
    }
    // the operator stack can have values.
    // so make it empty
    while(op.size() > 0){
        // work
        char ch = op.top();
        op.pop();
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1,val2,ch);
        val.push(ans);
    }
    return stoi(val.top());
}
*/