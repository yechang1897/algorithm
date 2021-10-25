#include<iostream>

using namespace std;

const int N = 10000;
int son[N][26];
int cnt[N];
int idx;

void insert(string s){
    int next = 0; // 下一个插入的层数
    int length = s.size();
    for(int i = 0; i < length; i++){
        int u = s[i]-'a';
        if(son[next][u] == 0) son[next][u] = ++idx;
        next = son[next][u];
    }
    cnt[next]++;
}
int query(string s){
    int next = 0; // 下一个插入的层数
    int length = s.size();
    for(int i = 0; i < length; i++){
        int u = s[i]-'a'; // 计算下标
        if(son[next][u] == 0) return 0;
        next = son[next][u];
    }
    return cnt[next];
}

int main() {
    insert("hello");
    insert("leetcode");
    cout << query("hello");
    cout << query("helln");
    cout << query("leetcod");
    return 0;
}