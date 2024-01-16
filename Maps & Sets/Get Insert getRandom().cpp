// LEETCODE 380

class RandomizedSet {
public:
    unordered_set<int> uset;
    RandomizedSet() {
        // unordered_set<int> uset;
    }
    
    bool insert(int val) {
        if(uset.find(val) == uset.end()){
            uset.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(uset.find(val) != uset.end()){
            uset.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randomIndex = rand() % uset.size();
        auto it = uset.begin();
        advance(it, randomIndex);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */