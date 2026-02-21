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

 /**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <unordered_map>
using namespace std;
struct Node {
    int key, val;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int k, int v) : key(k), val(v){} 
};
class LRUCache {
public:
    unordered_map<int, Node*> map;
    int capacity;
    Node* head;
    Node* tail;
    int len;

    LRUCache(int cap) {
        capacity = cap;
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    ~LRUCache() {
        for (auto pair : map) {
            if (pair.second != nullptr) {
                delete pair.second;
            }
        }
    }

    void updateNode(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    void addToHead(Node* node) {
        node->next = head;
        if (head != nullptr) {
            head->prev = node;
        }
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
    }

    void removeNode(Node* node) {
        if (node == tail) {
            tail = node->prev;
        }
        if (node == head) {
            head = node->next;
        }
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        node->prev = nullptr;
        node->next = nullptr;
    }

    int get(int key) {
        auto found = map.find(key);
        if (found != map.end()) {
            //cout<<"get "<<found->second->key<<endl;
            if (found->second != head) {
                updateNode(found->second);
            }
            print();
            return found->second->val;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto found = map.find(key);
        if (found != map.end()) {
            found->second->val = value;
            if (found->second != head) {
                updateNode(found->second);
            }
            //cout<<"updating "<<found->first<<endl;
        }
        else {
            Node* node = new Node(key, value);
            map.insert({key, node});
            addToHead(node);
            //cout<<"adding "<<key<<endl;
            print();
            ++len;
            if (len > capacity) {
                Node *oldTail = tail;
                //cout<<"erasing "<<oldTail->key<<endl;
                removeNode(oldTail);
                print();
                map.erase(oldTail->key);
                delete oldTail;
                --len;
            }
        }
    }

    void print() {
        #if 0
        Node* node = head;
        cout<<"print:";
        while(node != nullptr) {
            cout<<node->key<<' ';
            node = node->next;
        }
        cout<<endl;
        #endif
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

