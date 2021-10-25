#include<iostream>
#include<vector>

using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
    int flag = 3;
    for (int i : arr) {
        if (i % 2 == 1) {
            flag--;
        } else {
            flag = 3;
        }
        if(flag == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {1,2,34,3,4,5,7,23,12};
    cout << threeConsecutiveOdds(arr);
}