/*
// METHOD 1 : BRUTE FORCE
class MinStack{
    public:
    stack<int> st;
    MinStack(){ // constructor

    }

    void push(int val){
        st.push(val);
    }

    void pop(){
        st.pop();
    }

    int top(){
        return st.top();
    }

    int getMin(){
        stack<int> helper;
        int mn = INT_MAX;
        while(st.size() > 0){
            mn = min(mn, st.top());
            helper.push(st.top());
            st.pop();
        }

        while(helper.size() > 0){
            st.push(helper.top());
            helper.pop();
        }

        return mn;

    }
}
*/

/*
// METHOD 2 : by using extra stack that will always have the same no. of elements as your given st.
class MinStack{
    public:
    stack<int> st;
    stack<int> helper;
    MinStack(){ // constructor

    }

    void push(int val){
        st.push(val);
        if(helper.size() == 0 || val < helper.top()) helper.push(val);
        else helper.push(helper.top());
    }

    void pop(){
        st.pop();
        helper.pop();
    }

    int top(){
        return st.top();
    }

    int getMin(){
        return helper.top();

    }
}
*/

/*
// METHOD 3 : SC = O(1) TC = O(N)
    Implement the stack with vector & each time you call getmin -> O(n)
    You have to traverse the entire vector.

class MinStack{
    public:
    vector<int> v;
    MinStack(){ // constructor

    }

    void push(int val){
        v.push_back(val);
    }

    void pop(){
        v.pop_back();
    }

    int top(){
        return v[v.size() - 1];
    }

    int getMin(){
        int mn = v[0];
        for(int i = 1;i < v.size();i++){
            mn = min(mn,v[i]);
        }
        return mn;

    }
};

*/

/*
// METHOD 4 : TC = O(1) SC = O(1)

class MinStack{
    public:
    stack<long long> st;
    long long min;
    MinStack(){
        min = LLONG_MAX;
    }

    void push(int val){
        long long x = (long long)val;
        if(st.size() == 0){
            st.push(val);
            min = val;
        }
        else if(val >= min) st.push(val);
        else{
            // val < min
            st.push(2*val - min);
            min = val;
        }
    }

    void pop(){
        // O(1)
        if(st.top() >= min) st.pop();
        else{
            // st.top() < min : A fake value is present 
            // before popping make sure to retrieve the old min
            long long oldMin = 2*min - st.top();
            min = oldMin;
        }
        st.pop();
    }

    int top(){
        if(st.top() < min) return (int)min;
        else return (int)st.top();
    }

    int getMin(){
        
        return (int)mn;

    }


}



*/