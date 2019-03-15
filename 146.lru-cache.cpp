/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (24.25%)
 * Total Accepted:    267.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 * capacity * );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LRUCache {
public:
    struct Pair{
        int key = 0;
        int val = 0;
        unsigned int id = 0;
        Pair(int k, int v, unsigned int i): key(k), val(v), id(i) {}
    };
    
    vector<Pair> pairs;
    int capacity = 0;
    int recentId = 0;
    
    LRUCache(int cap) {
        capacity = cap;
        pairs.reserve(cap);
    }
    
    int get(int key) {
        for(int i = 0; i < pairs.size(); i++){
            if(pairs[i].key == key){
                pairs[i].id = recentId++;
                return pairs[i].val;
            }
                
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(pairs.size() >= capacity){
            int minId = pairs[0].id;
            int minIndex = 0;
            bool sameKey = false;
            int sameKeyIndex = -1;
            for(int i = 0 ; i < pairs.size(); i++){
                if(pairs[i].id < minId){
                    minId = pairs[i].id;
                    minIndex = i;
                }
                if(pairs[i].key == key){
                    sameKey = true;
                    sameKeyIndex = i;
                    break;
                }
            }
            if(sameKey){
                pairs[sameKeyIndex].id = recentId++;
                pairs[sameKeyIndex].key = key;
                pairs[sameKeyIndex].val = value;
            }
            else{
                pairs[minIndex].id = recentId++;
                pairs[minIndex].key = key;
                pairs[minIndex].val = value;
            }
            
        }
        else{
            bool sameKey = false;
            int sameKeyIndex = -1;
            for(int i = 0 ; i < pairs.size(); i++){
                if(pairs[i].key == key){
                    sameKey = true;
                    sameKeyIndex = i;
                    break;
                }
            }
            if(sameKey){
                pairs[sameKeyIndex].id = recentId++;
                pairs[sameKeyIndex].key = key;
                pairs[sameKeyIndex].val = value;
            }
            else
                pairs.push_back(Pair(key,value, recentId++));
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

