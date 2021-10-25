#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<pair<int,int>> frac(n);
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            frac[i].first = x;
            frac[i].second = y;
        }
        pair<int,int> res;
        res.first = frac[0].first;
        res.second = frac[0].second;
        for(int i = 1; i < n; i++) {
            int new1 = frac[i].second * res.second / gcd(frac[i].second,res.second);
            res.first = (new1 / frac[i].second) * frac[i].first + (new1 / res.second) * res.first;
            res.second = new1;
        }
        cout << res.first << " " << res.second << endl;
        if(res.first % res.second == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}