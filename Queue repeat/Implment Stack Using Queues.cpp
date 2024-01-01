// LEETCODE 225

/*
class MyStack{
public:
    queue<int> q;
    MyStack() {}

    void push(int x){
        q.push(x);
    }

    int pop(){
        int n = q.size();
        while(n > 1){
            q.push(q.front());
            q.pop();
            n--;
        }

        int val = q.front();
        q.pop();
        return val;
    }

    int top(){
        return q.back();
    }

    bool empty(){
        return q.size()==0;
    }
}
*/