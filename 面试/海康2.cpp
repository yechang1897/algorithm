#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> buckets(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> buckets[i][j];
        }
    }

    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            int l = buckets[i][j - 1];
            int r = buckets[i][j + 1];
            int minT = min(l, r);
            if(buckets[i][j] < minT) {
                res[i][j] = minT - buckets[i][j];
            }
        }
    }

    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int t = buckets[j - 1][i];
            int b = buckets[j + 1][i];
            int minT = min(t, b);
            if(buckets[i][j] < minT) {
                res[i][j] = min(res[i][j], minT - buckets[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            ans += res[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}