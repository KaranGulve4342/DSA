/*
class Solution{
public:
    stack<int> st;
    stack<int> helper;
    MyQueue(){

    }

    void push(int x){
        st.push(x);
    }

    int pop(){
        // remove at bottom
        while(st.size() > 0){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }

    int peek(){
        // retreive at bottom
        while(st.size() > 0){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }

    bool empty(){
        if(st.size() == 0) return true;
        else return false;
    }
};
*/

// method II
/*
class Solution{
public:
    stack<int> st;
    stack<int> helper;
    MyQueue(){

    }

    void push(int x){
        // push at bottom
        if(st.size() == 0){
            st.push(x);
            return;
        }
        else{
            while(st.size() > 0){
                helper.push(st.top());
                st.pop();
            }
            st.push(x);
            while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
            }
        }
    }

    int pop(){
        int x = st.top();
        st.pop();
        return x;
    }

    int peek(){
        return st.top();
    }

    bool empty(){
        if(st.size() == 0) return true;
        else return false;
    }
};
*/