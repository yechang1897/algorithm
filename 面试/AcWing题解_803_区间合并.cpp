#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e6 + 10;
typedef pair<int,int> PII;
vector<PII> alls;
int n;

void merge(vector<PII>& alls) {
    vector<PII> res;

    sort(alls.begin(), alls.end());
    int st = -2e9, ed = -2e9;
    for(auto x : alls) {
        if(x.first > ed) {
            if(st != -2e9) res.push_back({st, ed});
            st = x.first, ed = x.second;
        } else {
            ed = max(ed, x.second);
        }
    }
    if(st != -2e9) res.push_back({st, ed});
    alls = res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        alls.push_back({l, r});
    }
    merge(alls);
    cout << alls.size(); 
}