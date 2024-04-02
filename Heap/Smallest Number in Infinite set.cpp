// LEETCODE 2336

class SmallestInfiniteSet {
    // set<int> uset;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SmallestInfiniteSet() {
        for(int i = 1000;i >= 1;i--){
            // uset.insert(i);
            pq.push(i);
        }
    }

    int popSmallest() {
        // int smallest = *uset.begin();
        // uset.erase(smallest);
        int smallest = pq.top();
        pq.pop();
        while(!pq.empty() && pq.top() == smallest){
            pq.pop();
        }
        return smallest;
    }

    void addBack(int num) {
        // if(num > 0 && !uset.count(num)){
            // uset.insert(num);
        // }
        if(num > 0){
            pq.push(num);
        }
    }
};
