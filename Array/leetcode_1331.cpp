#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> temp = arr;
    int sz = (int)temp.size();
    sort(temp.begin(), temp.end());
    for(int i = 0; i < sz - 1; ++i) {
        if(temp[i] == temp[i + 1]) {
            for(int j = i + 1; j < sz - 1; ++j) {
                temp[j] = temp[j + 1];
            }
            temp.pop_back();
        }
    }
    // for (int i : temp) {
    //     cout << i << " ";
    // }
    // cout << endl;
    vector<int> res(sz);
    for(int i = 0; i < sz; ++i) {
        for(int j = 0; j < sz; ++j) {
            if(arr[i] == temp[j]) {
                res[i] = j + 1;
                break;
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {37,12,28,9,100,56,80,5,12};
    for(int i :arrayRankTransform(arr)) {
        cout << i << " ";
    }
}