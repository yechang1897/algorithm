#include<iostream>

using namespace std;
const int N = 1e5 + 5;
int stk[N], top = 0;
int main() {
    int M;
    cin >> M;
    while(M--) {
        string op;
        cin >> op;
        if(op == "push") {
            int x;
            cin >> x;
            stk[++top] = x;
        } else if(op == "pop") {
            top--;
        } else if(op == "query") {
            cout << stk[top] << endl;
        } else if(op == "empty") {
            cout << (top ? "NO" : "YES") << endl;
        }        
    }
    return 0;
}