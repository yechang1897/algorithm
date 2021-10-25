#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int que[N], head, tail = -1;
int main() {
    int m;
    cin >> m;
    while(m--) {
        string op;
        cin >> op;
        if(op == "push") {
            int x;
            cin >> x;
            que[++tail] = x;
        } else if(op == "pop") {
            head++;
        } else if(op == "query") {
            cout << que[head] << endl;
        } else {
            cout << (head <= tail ? "NO" :"YES") << endl;
        }
    }
    return 0;
}