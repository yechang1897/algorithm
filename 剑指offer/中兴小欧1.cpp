#include<iostream>
#include<vector>
using namespace std;

int getMaxMoney(vector<int>& v , vector<int>& w, int Att, int V) {
    int N = v.size();
    vector<int> dp(V + 1);    
    for(int i = 1; i <= N; ++i) {
        for (int j = V; j >= (v[i] / Att) * w[i] ; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    return dp[V];
}

int fun(int Hp, int Att, vector<int>& h, vector<int>& a, vector<int>& m) {
    int sh = h.size();
    int res = 0;
    vector<int> v;
    vector<int> w;
    for(int i = 0; i < sh; i++) {
        if(h[i] <= Att) {
            res += m[i];
        } else {
            v.push_back(a[i]);
            w.push_back(m[i]);
        }
    }
    int t = getMaxMoney(v, w, Att,Hp - 1);
    return res + t;
}

int main() {
    int Hp = 1, Att = 1;
    vector<int> h = {1, 1, 2, 1};
    vector<int> a = {1, 1, 1, 1};
    vector<int> m = {1, 2, 4, 8};
    cout << fun(Hp, Att, h, a, m);
    return 0;
}