#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> t(K);
    for(int i = 0; i < K; i++) {
        int start, up, down;
        cin >> start >> up >> down;
        t[i].first = start;
        t[i].second = start + min(abs(up - down), N - abs(up - down)) * 5;
    }
    int res = 0;
    int maxT = t[K - 1].second;
    for(auto x : t) {
        cout << x.first << " " << x.second << endl;
    }
    for(int i = 0; i < maxT; i++) {
        int temp = 0;
        for(int j = 0; j < K; j++) {
            if(i >= t[j].first && i < t[j].second) {
                temp++;
            }
        }
        res = max(res, temp);
    }
    
    cout << res;
    return 0;
}