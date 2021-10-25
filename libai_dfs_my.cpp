#include<iostream>

using namespace std;
int res = 0;
int dfs(int store, int flower, int alcohol){
    if (store == 0 && flower == 0 && alcohol == 1) {
        res++;
    }
    if (store > 0) {
        dfs(store - 1, flower, alcohol * 2);
    }
    if (flower > 0) {
        dfs(store, flower - 1, alcohol - 1);
    }
    return res;
}

int main(){
    cout << dfs(5, 9, 2);
    return 0;
}