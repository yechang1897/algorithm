#include<iostream>
#include<vector>
using  namespace std;

vector<int> quickSort(vector<int>& arr, int k, int l, int r) {
    int i = l, j = r;
    while(i < j) {
        while(i < j &&  arr[j] >= arr[l]) j--;
        while(i < j &&  arr[i] <= arr[l]) i++;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[l]);
    if(i > k) return quickSort(arr, k, l, i - 1);
    if(i < k) return quickSort(arr, k, i + 1, r);
    vector<int> res;
    res.assign(arr.begin(), arr.begin() + k);
    return res;
}

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (k >= arr.size()) return arr;
    return quickSort(arr, k, 0, arr.size() - 1);
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