#include<iostream>
#include<algorithm>
#include<list>

using namespace std;
//拉链法
class MyHashMap {
public:
    /*
    初始化哈希表桶的大小,20011,质数且离2的幂足够远。
    */
    const static int N = 20011;

    vector<list<pair<int,int>>> hash;

    /** Initialize your data structure here. */
    
    MyHashMap() {
        hash = vector<list<pair<int,int>>>(N);
    }
key
    list<pair<int,int>>:: iterator find(int key){
        int t = key % N;
        auto it = hash[key];
        for(; it != hash[t].end(); it++) {
            if(it->first == key) 
                break;
        }
        return it;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int t = key % N;
        auto it = find(t);
        if(it == hash[t].end()) 
            hash[t].push_back(make_pair(key, value));
        else 
            it->second = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto it = hash.find(key);
        if(it == hash[key % N].end())
            return -1;
        return it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int t = key % N;
        auto it = find(key);
        if  (it != hash[t].end())
            hash[t].erase(it);
    }
}
