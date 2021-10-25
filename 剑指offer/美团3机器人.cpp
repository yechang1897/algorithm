#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> l;
    vector<pair<int,int>> r;
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        int num;
        string dire;
        cin >> num >> dire;
        if(dire == "L") l.push_back({num, i});
        else r.push_back({num, i});
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int t = 0;
    while(true) {
        t++;
        for(int i = 0; i < l.size(); i++) {
            if(l[i].first != -1)
                l[i].first--;
        }
        for(int i = 0; i < r.size(); i++) {
            if(r[i].first != -1)
                r[i].first++;
        }

        for(int i = 0; i < l.size(); i++) {
            for(int j = 0; j < r.size(); j++) {
                if(l[i].first == r[j].first) {
                    res[l[i].second] = t;
                    res[r[j].second] = t;
                    l.erase(l.begin() + i);
                    r.erase(r.begin() + j);
                }
            }
        }
        if(l.empty() || r.empty()) {
            
            if(l.empty()) {
                for(int i = 0; i < r.size(); i++) {
                    res[r[i].second] = -1;
                }
            } else {
                for(int i = 0; i < l.size(); i++) {
                    res[l[i].second] = -1;
                }
            }
            break;
        }

        if(l.back().first < r.front().first) {
            for(int i = 0; i < r.size(); i++) {
                res[r[i].second] = -1;
            }
            for(int i = 0; i < l.size(); i++) {
                    res[l[i].second] = -1;
            }
            break;
        }
    }
    for(auto x : res) {
        cout << x << endl;
    }
    return 0;
}