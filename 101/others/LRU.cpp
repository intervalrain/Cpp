#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator hash;
    list<pair<int, int>> cache;
    int size;
public:
    LRUCache(int capacity):size(capacity) {}

    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end()){
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int val){
        auto it = hash.find(key);
        if (it != hash.end()){
            it->second->second = val;
            return cache.splice(cache.begin(), cache, it->second);
        }
        cache.insert(cache.begin(), make_pair(key, val));
        hash[key] = cache.begin();
        if (cache.size() > size){
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
};
