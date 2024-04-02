// LEETCODE 2424

class LUPrefix {
public:
    int count;
    priority_queue<int, vector<int>, greater<int>> pq;
    LUPrefix(int n) {
        count = 0;
    }
    
    void upload(int video) {
        pq.push(video);
    }
    
    int longest() {
        while(pq.size() && pq.top() == count + 1){
            pq.pop();
            count++;
        }
        return count;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */