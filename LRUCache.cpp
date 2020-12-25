class LRUCache {
    int size;
    unordered_map<int, int> lrucache;
    list<int> lruque;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(lrucache.find(key) != lrucache.end())
        {
            lruque.remove(key);
            lruque.push_back(key);
            return lrucache[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(lrucache.find(key) != lrucache.end())
        {
            lrucache.erase(key);
            lruque.remove(key);
        }
        if(size == lrucache.size())
        {
            int key = lruque.front();
            lruque.pop_front();
            lrucache.erase(key);
        }
        lruque.push_back(key);
        lrucache[key] = value;
    }
}
