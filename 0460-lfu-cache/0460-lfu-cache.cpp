

class LFUCache {
private:
    int cap, minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq; // key -> {value, freq}
    unordered_map<int, list<int>> freqToKeys;        // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freqToKeys

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end())
            return -1;

        // Get current value and frequency
        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;

        // Remove from current freq list
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        // Update freq
        freq++;
        keyToValFreq[key].second = freq;
        freqToKeys[freq].push_front(key);
        keyToIter[key] = freqToKeys[freq].begin();

        return val;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key); // update frequency
            return;
        }

        // If at capacity, remove LFU key
        if (keyToValFreq.size() == cap) {
            int evictKey = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty()) {
                freqToKeys.erase(minFreq);
            }
            keyToValFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }

        // Insert new key
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};
