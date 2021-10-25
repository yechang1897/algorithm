#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int SIZE = 1e6 + 10;

int trie[SIZE][26], cnt[SIZE];
char str[SIZE];

int n, m, idx = 0;

void insert() {
    int sz = strlen(str), p = 0;
    for(int i = 0; i < sz; i++) {
        int ch = str[i] - 'a';
        if(trie[p][ch] == 0) trie[p][ch] = ++idx;
        p = trie[p][ch];
    }
    cnt[p]++;
}


int query() {
    int sz = strlen(str), p = 0;
    int res = 0;
    for(int i = 0; i < sz; i++) {
        int ch = str[i] - 'a';
        if(trie[p][ch] != 0) {
            p = trie[p][ch];
            res += cnt[p];
        } else {
            break;
        }
    }
    return res;
}
int main() {
    void insert();
    int query();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        insert();
    }
    for(int i = 0; i < m; i++) {
        scanf("%s", str);
        cout << query() << endl;
    }
    return 0;
}

/**
3 2
ab
bc
abc
abc
efg
**/

/**
插入:
void insert(char str[]) {
    int len = strlen(str),p = 0;                        // p 作为根节点从 0 开始
    for(int i = 0; i < len; i ++) {
        int ch = str[i] - 'a';
        if(trie[p][ch] == 0) trie[p][ch] = ++ idx;  // 创建新的节点
        p = trie[p][ch];                            // 指针移动
    }
    End[p] = true;                                      // 在末尾进行标记
    return ;
}

检索:
bool query(char str[]) {
    int len = strlen(str),p = 0;
    for(int i = 0; i < len; i ++ ){
        int ch = str[i] - '0';
        if(trie[p][ch] != 0) {
            p = trie[p][ch];
        } else {
            break;                            // 及时跳出
        }
    } 
    return true;
}
**/
