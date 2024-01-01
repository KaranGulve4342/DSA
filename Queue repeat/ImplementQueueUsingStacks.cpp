// LEETCODE 232


// METHOD 1 : push efficient approach
/*
class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    MyQueue() {
        
    }
    
    void push(int x) { // O(1)
        st.push(x);
    }
    
    int pop() { // O(n);
        // remove at bottom
        while(st.size() > 0){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        while(helper.size() > 0){
            st.push(helepr.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() {
        
    }
    
    bool empty() {
        if(st.size() == 0) return true;
        else return false;
    }
};


*/

// METHOD 2 : pop-peek efficient approach
/*
class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    MyQueue() {
        
    }
    
    void push(int x) {
        // push at bottom
        if(st.size() == 0){
            st.push(x);
            return;
        }
        else{
            while(st.size() > 0){
                helper.push(st.top())
                st.pop();
            }
            st.push(x);
            while(helepr.size() > 0){
                st.push(helper.top());
                helper.top();
            }
        }
    }
    
    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        
    }
};

*/
