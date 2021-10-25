#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int numSquares(int n) {
    queue<int> q;
    vector<int> dist(n + 1, INT_MAX - 1);
    q.push(0);
    dist[0] = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        if(t == n) return dist[t];
        cout << "t:" << t <<endl;
        for (int i = 1; i * i + t <= n; i++) {
            int j = i * i + t;
            cout << "j:" << j << endl;
            if(dist[j] > dist[t] + 1) {
                dist[j] = dist[t] + 1;
                q.push(j);
            }
        }
    }  
    return 0;
}

int main() {
    int n = 12;
    cout << numSquares(n);
}