#include<iostream>
#include<string>
using namespace std;

const int N = 100010;

int idx, head, n[N], ne[N];

void add_head(int x) {
    n[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add(int k, int x) {
    n[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    head = -1; idx = 0;
    int M;
    cin >> M;
    while(M--) {
        string op;
        int k, x;
        cin >> op;
        if(op == "H") {
            cin >> x;
            add_head(x);
        } else if(op == "I") {
            cin >> k >> x;
            add(k - 1, x);
        } else if(op == "D") {
            cin >> k;
            if(!k) head = ne[head];
            remove(k - 1);
        }
    }
    for(int i = head; i != -1; head = ne[i]) {
        cout << e[i] << " ";
    }
    return 0;
}
