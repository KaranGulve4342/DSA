// LEETCODE 155

/*
stack<long long> st;
long long min;
MinStack(){
    // constructor
    min = LLONG_MAX;
}

void push(int val){
    long long x = (long long)val;
    if(st.size() == 0){
        st.push(x);
        min = x;
    }
    else if(x >= min) st.push(x);
    else{
        // val < min
        st.push(2*x - min);
        min = x;
    }
}

void push(int val){
    if(st.size() == 0){
        st.push(val);
        min = val;
    }
    else if(val >= min) st.push(val);
    else{
        // val < min
        st.push(2*val - min);
        min=  val;
    }
}

void pop(){
    if(st.top() < min){
        // a fake vak=lue is present
        // before popping make sure to retrieve
        int oldMin = 2*min - st.top();
        min = oldMin;
    }
    st.pop();
}
int top(){
    if(st.top() < min) return (int)min;
    else return (int)st.top();
}

int getMin(){
    return (int)min;
}
*/