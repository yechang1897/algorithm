#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

struct Node{
    int key;
    int value;
    int fre;
};

class LFUCache{
    using NodeList = list<Node>;
    using NodeIt = list<Node>::iterator;
    unordered_map<int, NodeList> frememo;
    unordered_map<int, NodeIt> keymemo;
    int cap;
    int minFre = 0;

    public:
        LFUCache(int capacity) {
            cap = capacity;
        }

        int get(int key) {
            auto keyIt = keymemo.find(key);
            if(!cap || keyIt == keymemo.end()) return -1;
            NodeIt it = keyIt->second;

            auto& newList = frememo[it->fre + 1];
            newList.splice(newList.begin(), frememo[it->fre], it);
            if(!frememo[it->fre].size()) {
                frememo.erase(it->fre);
                if(minFre == it->fre) {
                    minFre++;
                }
            }

            it->fre++;
            return it->val;
        }

        void put(int key, int value) {
            if(!cap) {
                return;
            }

            auto keyIt = keymemo.find(key);
            if(keyIt != keymemo.end()) {
                keyIt->second = value;
                get(key);
            } else {
                if(keymemo.size() == cap) {
                    auto tmp = keymemo[minFre].back().key;
                    keymemo.erase(tmp);
                    frememo[minFre].pop_back();
                    if(frememo[minFre].size() == 0) {
                        frememo.erase(minFre);
                    }
                }
                frememo[1].push_front({key, value, 1});
                keymemo[key] = frememo[1].begin();
                minFre = 1;
            }
        }


}