#include<iostream>
#include<algorithm>
#include<list>
#include<cstring.h>

using namespace std;
//开放地址法
class MyHashMap{
public:
    const int N = 20011;
    int hash_key[N], hash_value[N];

    MyHashMap() {
        memset(hash_key, -1, sizeof hash_key);
    }

    int find(int key, bool is_put) {
        int t = key % N;
        while(hash_key[t] != key && hash_key[t] != -1) {
            if(is_put && hash_key[t] == -2) 
                break;
            if(++t == N) t = 0;
        }
        return t;
    }

    void put(int key, int value) {
        int t = find(key, true);
        hash_key[t] = key;
        hash_value[t] = value;
    }

    int get(int key) {
        int t = find(key, false);
        if  (hash_key[t] == - 1) return -1;
        return hash_value[t];
    }

    void remove(int key) {
        int t = find(key, false);
        if(hash_key[t] != -1) 
            hash_key[t] = -2;
    }
}