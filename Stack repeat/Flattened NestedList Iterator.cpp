// LEETCODE 341

/*
class NestedIterator {
public:
    stack<NestedInteger> stack;

    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1;i >= 0;i--){
            stack.push(nestedList[i]);
        }
    }
    
    int next() {
        makeStackTopAnInteger();

        int result = stack.top().getInteger();
        stack.pop();
        return result;
    }
    
    bool hasNext() {
        makeStackTopAnInteger();

        return !stack.empty();
    }

    void makeStackTopAnInteger(){
        while(!stack.empty() && !stack.top().isInteger()){
            vector<NestedInteger> nestedList = stack.top().getList();
            stack.pop();
            for(int i = nestedList.size() - 1;i >= 0;i--){
                stack.push(nestedList[i]);
            }
        }
    }
};

*/