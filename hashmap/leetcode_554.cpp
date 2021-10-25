#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> hash;
    int s;
    int res = 0;
    for(auto w : wall) {
        s = 0;
        for(int i = 0; i + 1 < (int)w.size(); i++) {
            s += w[i];
            hash[s]++;
            res = max(res, hash[s]);
        }
    }
    cout << res << endl;
    return wall.size() - res;
}

int main() {
    vector<vector<int>> wall = {{100000000},{100000000},{100000000}};
    cout << leastBricks(wall);
}