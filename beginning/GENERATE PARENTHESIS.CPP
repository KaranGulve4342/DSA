// LEETCODE 22

/*
void helper(vector<string>& combinations, string current, int openCount, int closeCount, int n){
    if(current.length() == 2*n){
        combinations.push_back(current);
        return;
    }

    if(openCOunt < n){
        helper(combinations, current + '(', openCount + 1, closeCount, n);
    }

    if(closeCount < openCount){
        helper(combinations, current + ')', openCount, closeCount +  1, n);
    
}
vector<string> generateParenthesis(int n){
    vector<string> combinations;
    helper(combinations, "", 0, 0, n);
    return combinations;
}
*/