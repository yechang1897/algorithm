#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool check(int x, vector<int>& position, int m) {
    int pre = position[0], cnt = 1;
    for (int i = 1; i < (int)position.size(); ++i) {
        if (position[i] - pre >= x) {
            pre = position[i];
            cnt += 1;
        }
    }
    return cnt >= m;
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int left = 1, right = position.back() - position[0], ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, position, m)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> position = {1,2,3,4,7};
    int m = 3;
    cout << maxDistance(position, m);
}