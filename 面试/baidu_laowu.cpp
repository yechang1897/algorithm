#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;



vector<int> findContentChildren(vector<int>& g, vector<int>& s) {
    vector<int> res;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    for(j = 0; j < (int)s.size() && i < (int)g.size(); ++j) {
        while(s[j] >= g[i]) {
            i++;
            res.push_back(i);
            cout << i << endl;
            break;
        }
    }
    // for(auto item : res) {
    //     cout << item << " ";
    // }
    // cout << endl;
    return res;
}


int main() {
	// int t;
	// cin >> t;
	// for (int i = 0; i < t; ++i) {
	// 	int n, m;
	// 	cin >> n >> m;
	// 	vector<vector<int>> parter;
	// 	vector<vector<int> > com;
	// 	for (int j = 0; j < n; ++j) {
	// 		int x;
	// 		cin >> x;
	// 		parter.push_back({ x,j + 1 });
	// 	}
	// 	for (int j = 0; j < m; ++j) {
	// 		int x;
	// 		cin >> x;
	// 		com.push_back({ x,j + 1 });
	// 	}
    // }
        
	// 	for(auto item : findContentChildren(parter, com)) {
    //         cout << item << " ";
    //     }
    vector<int> g = {33, 66, 99};
    vector<int> s = {3, 6, 9, 30, 60, 90};
     
    for(auto item : findContentChildren(g, s)) {
        cout << item << " ";
    }

}