#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
        if(s.size() % 2 != 0) return false;

        stack<char> open;
        stack<char> close;

        for(int i = 0;i < s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' )  open.push(s[i]);    

            else if (!open.empty() && ((s[i] == ')' && open.top() == '(') || (s[i] == ']' && open.top() == '[') || (s[i] == '}' && open.top() == '{'))){
                close.push(s[i]);
                open.pop();
            }   
        }

        if(2*close.size() == s.size()) return true;
        return false;
}

int main(){
    string s = "()[]{}";
    cout<<s.size()<<endl;
    cout<<isValid(s)<<endl;
}