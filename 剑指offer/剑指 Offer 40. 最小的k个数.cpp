#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    int sz = arr.size();
    if(sz == k) return arr;
    vector<int> res;
    priority_queue<int> que;
    for(int i = 0; i < k; i++) {
        que.push(arr[i]);
    }
    for(int i = k; i < sz; i++) {
        if(arr[i] < que.top()) {     
            que.pop();
            que.push(arr[i]); 
        }
    }
    for(int i = 0; i < k; i++) {
        res.push_back(que.top());
        que.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> arr = {3, 2, 1};
    int k = 2;
    for(auto x : getLeastNumbers(arr, k)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}