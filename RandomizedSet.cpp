class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> data;
    map<int, int> dataindmap;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dataindmap.find(val) == dataindmap.end())
        {
            data.push_back(val);
            dataindmap[val] = data.size()-1;
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dataindmap.find(val) != dataindmap.end())
        {
            int ind = dataindmap[val];
            dataindmap.erase(val);
            swap(data[ind], data[data.size()-1]);
            data.pop_back();
            if(ind < data.size())
                dataindmap[data[ind]] = ind;
            return true;
        }
        else
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randnum = rand() % data.size();
        return data[randnum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
