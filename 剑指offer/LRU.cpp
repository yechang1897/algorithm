#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;



struct Node{
    int key;
    int value;
};

class LRUCache{
    list<Node> ilist;
    using nodeIt = list<Node>::iterator;
    unordered_map<int, nodeIt> memo;
    int cap;


    public:
    LRUCache(int capacity) {cap = capacity};

    int get(int key) {
        auto it = memo.find(key);
        if(it != memo.end()) {
            ilist.splice(ilist.begin(), ilist, it->second);
            return it->second->value;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        auto it = memo.find(key);
        if(it != memo.end()) {
            ilist.splice(ilist.begin(), ilist, it);
            it->second->value = value;
        } else {
            ilist.push_front({key, value});
            memo.insert({key, ilist.begin()});
            if(ilist.size() > cap) {
                memo.erase(ilist.back().key);
                ilist.pop_back();
            }
        }
    }
}