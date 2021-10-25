#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1e6 + 10;

int trie[SIZE][26],cnt[SIZE];
char str[SIZE];
int n,m,idx = 0;

int main(void) {
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++) {
        scanf("%s",str);
        insert();
    }
    while(m --) {
        scanf("%s",str);
        printf("%d\n",query());
    }
    return 0;
} 

void insert() {
    int p = 0;
    for(int i = 0; i < strlen(str); i ++) {
        int ch = str[i] - 'a';
        if(trie[p][ch] == 0) trie[p][ch] = ++ idx;
        p = trie[p][ch];
    }
    cnt[p] ++;                            // 统计该字符串的个数
    return ;
}

int query() {
    int p = 0,res = 0;
    for(int i = 0 ; i < strlen(str); i ++) {
        int ch = str[i] - 'a';
        if(trie[p][ch] != 0) {
            p = trie[p][ch];
            res += cnt[p];           // 将以该字符结尾的数量累加,最后结果就是前缀字符串的数量
        } else {
            break;
        }
    }
    return res;
}