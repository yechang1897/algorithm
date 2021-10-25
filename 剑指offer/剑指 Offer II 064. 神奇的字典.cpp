#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int N = 105;
int trie[N][26], cnt[N];
int idx = 0;

// void buildDict(vector<string> dictionary) {
//     for(auto str : dictionary) {
//         insert(str);
//     }
// }

void insert(string s) {
    int p = 0;
    for(int i = 0; i < s.size(); i ++) {
        int ch = s[i] - 'a';
        if(trie[p][ch] == 0) trie[p][ch] = ++ idx;
        p = trie[p][ch];
    }
    cnt[p] ++;                            // 统计该字符串的个数
    return ;
}

bool query(string s) {
    int p = 0;int flag = 1;
    for(int i = 0 ; i < s.size(); i ++) {
        int ch = s[i] - 'a';
        if(trie[p][ch] != 0) {
            p = trie[p][ch];
           // 将以该字符结尾的数量累加,最后结果就是前缀字符串的数量
        } else {
            if(flag == 1){ 
                p++;
                flag--;
            }
            else if(flag == 0) return false;
        }
    }
    return true;
}

int main() {
    insert("hello");
    insert("leetcode");
    cout << query("helloo");
    cout << query("hhllo");
    cout << query("hell");
    cout << query("leetcoded");
    return 0;
}