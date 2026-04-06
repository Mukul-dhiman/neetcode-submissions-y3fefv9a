class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    list<int> order;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            auto itr = mp[key].second;
            order.erase(itr);
            order.push_back(key);
            mp[key].second = --order.end(); 
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(cap==mp.size()){
                int lru = order.front();
                order.pop_front();
                mp.erase(lru);
            }
        }
        else{
            order.erase(mp[key].second);
        }
        order.push_back(key);
        mp[key] = {value, --order.end()};
    }
};
