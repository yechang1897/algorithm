#include<iostream>
#include<vector>
#include<bitset>
#include<string>
using namespace std;

int main() {
    vector<int> a = {5, 2, 12, 18, 7, 9, 13, 19, 16, 4, 6};
    string str = "woxdaxodauz123AADUIEF";
    vector<int> b(128);
    // int sz = a.size();
    // for(int i = 0; i < sz; i++) {
    //     b.set(a[i]);
    // }
    // for(int i = 0; i < 20; i++) {
    //     if(b.test(i)) cout << i << " ";
    // }
    int sz = str.size();
    for(int i = 0; i < sz; i++) {
        b[str[i]]++;
    }
    for(int i = 0; i < 128; i++) {
        if(b[i] != 0) {
            for(int j = 0; j < b[i];j++) {
                printf("%c ", i);
            }
        }
    }
    puts("");
    return 0;
}