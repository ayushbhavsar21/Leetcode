class LRUCache {
private:
    int capacity; // Maximum capacity of the cache
    list<pair<int, int>> cache; // Doubly linked list to store keys and values
    unordered_map<int, list<pair<int, int>>::iterator> map; // Hash map for O(1) access to cache nodes

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1; // Key not found
        }
        // Move the accessed key-value pair to the front of the list (most recently used)
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second; // Return the value
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Key exists, update its value and move to the front
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
        } else {
            // Key doesn't exist, add it to the cache
            if (cache.size() == capacity) {
                // Cache is full, remove the least recently used item
                int lruKey = cache.back().first;
                cache.pop_back();
                map.erase(lruKey);
            }
            // Insert the new key-value pair at the front
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
