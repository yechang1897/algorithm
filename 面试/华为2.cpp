#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> nums(K, vector<int>(2));
    for(int i = 0; i < K; i++) {
        int T, P;
        cin >> T >> P;
        nums[i][0] = T;
        nums[i][1] = P;
    }
    sort(nums.begin(), nums.end(), [](vector<int> a, vector<int> b){
        return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
    });
    int time[N];
    for(int i = 0; i < N; i++) {
        time[i] = nums[i][0];
    }
    for(int i = N; i < K;i++) {
        int minI = 0;
        for(int j = 0; j < N; j++) {
            if(time[j] <= time[minI]) {
                minI = j;
            }
        }
        cout << minI << endl;
        time[minI] += nums[i][0];  
    }
    for(auto x : time) {
        cout << x << endl;
    }
    cout << *max_element(time, time + N);
    return 0;
}