#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> sweep;
int N, K;

int main() {
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        int t;
        cin >> t;
        sweep.push_back(t);
    }
    sort(sweep.begin(), sweep.end());
    int res = 0;
    int start = 0;
    int end = 0;
    for(int i = 0; i < sweep.size() - 1; i++) {
        // cout << sweep[i + 1] << " " << sweep[i] <<endl;
        end = (sweep[i + 1] + sweep[i]) >> 1;
        int t = (end - start) * 2;
        res = max(t, res);        
        start = end + 1;
    }
    end = N;
    // cout << "start: " << start << "end: " << end << endl;
    res = max(res, 2 * (end - start));
    cout << res << endl;
}