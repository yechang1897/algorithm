#include<iostream>
#include<vector>

using namespace std;

int hIndex(vector<int>& citations) {
    int n = (int)citations.size();
    int pivot, left = 0, right = n - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      cout << left << " " << pivot << " "<< right <<   endl;
      if (citations[pivot] == n - pivot) return n - pivot;
      else if (citations[pivot] < n - pivot) left = pivot + 1;
      else right = pivot - 1;
    }
    return n - left;
}

int main() {
    vector<int> citations = {0,1,4,5,6};
    cout << hIndex(citations);
}