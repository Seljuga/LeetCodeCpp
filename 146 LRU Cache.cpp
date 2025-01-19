class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> map;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        dll.erase(map[key].first);
        dll.push_front(key);
        map[key].first = dll.begin();
        return map[key].second;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            map[key].second = value;
            dll.erase(map[key].first);
            dll.push_front(key);
            map[key].first = dll.begin();
        }
        else {
            dll.push_front(key);
            map[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0) {
            int lastNodeKey = dll.back();
            map.erase(lastNodeKey);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
