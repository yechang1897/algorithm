#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> grades(n);
    for(int i = 0; i < n; i++) {
        cin >> grades[i];
    }
    sort(grades.begin(), grades.end());
    vector<int> dailygrade;
    int t = 100;
    dailygrade.push_back(100);
    for(int i = grades.size() - 2; i >= 0; i--) {
        if(grades[i] < grades[i + 1]) {
            t--;
            dailygrade.push_back(t);
        }
        dailygrade.push_back(t);
    }
    // cout << grades.size() <<" " << dailygrade.size() << endl;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        double t = dailygrade[i] * p + grades[i] * q;
        double total = t / 100.0;
        // cout << total << endl;
        if(total >= 60.0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}