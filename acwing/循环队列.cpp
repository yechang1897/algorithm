#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int cque[N], head, tail;
int main() {
    int m;
    cin >> m;
    while(m--) {
        string op;
        cin >> op;
        if(op == "push") {
            int x;
            cin >> x;
            cque[tail++] = x;
            if(tail == N) tail = 0;
        } else if(op == "pop") {
            head++;
            if(head == N) head = 0;
        } else if("query") {
            cout << cque[head] << endl;
        } else {
            cout << (head != tail ? "NO" : "YES") << endl; 
        }
    }
    return 0;
}