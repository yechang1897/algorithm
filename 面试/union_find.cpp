#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1000010;
int father[N];
int n;

void init() {
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int get(int x) {
    if(father[x] == x) {
        return x;
    }
    return get(father[x]);
}

/*
路径压缩查找
*/
int get2(int x) {
    if(father[x] == x) {
        return x;
    }
    return father[x] = get(father[x]); 
}


void merger(int x, int y) {
    x = get(x);
    y = get(y);
    if(x != y) {
        father[y] = x;
    }
}

int main() {

}