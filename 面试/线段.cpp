#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T;
    vector<pair<int,int>> segs;
    while(T--) {
        int l, r;
        cin >> l >> r;
        segs.push_back(make_pair(l,r));
    }
    sort(segs.begin(), segs.end());
    bool flag = false;
    for(int i = 0; i < segs.size() - 1; i++) {
        if(segs[i].second > segs[i + 1].segs) flag = true;
    }
    if(flag) cout << "true" << endl;
    else cout << "false" << endl;
}