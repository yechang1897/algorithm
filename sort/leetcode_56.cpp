#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
        if(intervals.size() == 0) {
            return res;
        }
        int len = (int)intervals.size();
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1;
        res.push_back(intervals[0]);
        while (i < len && j < len) {
            if(res[i][1] >= intervals[j][1]) {
                j++;
            } else if (res[i][1] >= intervals[j][0]) {
                res[i][1] = intervals[j][1];
                j++;
            } else {
                res.push_back(intervals[j++]);
                i++;
            }
        }
        return res;
}

int main() {
    vector<vector<int>> arys = {{1, 4}, {2, 3}};
    for (vector<int> ary : merge(arys)) {
        for (int i : ary) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}