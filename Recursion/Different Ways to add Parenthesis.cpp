LEETCODE 241

/*
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for(int i = 0;i < expression.length();i++){
            int curr = expression[i];
            if(curr == '+' || curr == '-' || curr == '*'){
                vector<int> first_half = diffWaysToCompute(expression.substr(0, i));
                vector<int> second_half = diffWaysToCompute(expression.substr(i+1));

                for(auto first : first_half){
                    for(auto second : second_half){
                        if(curr == '+'){
                            ans.push_back(first + second);
                        }
                        else if(curr == '-'){
                            ans.push_back(first - second);
                        }
                        else ans.push_back(first * second);
                    }
                }
            } 
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
};
*/