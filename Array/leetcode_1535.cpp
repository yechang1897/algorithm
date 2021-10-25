#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void moveArr(vector<int>& arr) {
    int last = arr[1];
    for(int i = 1; i < (int)arr.size() - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[(int)arr.size() - 1] = last;
}

int getWinner(vector<int>& arr, int k) {
     
    int winCount = 0;
    int winner = 0;
    while (winCount < k) {
        if (arr[0] > arr[1]) {
            winner = arr[0];
            winCount++;
            moveArr(arr);
        } else {
            winner = arr[1];
            winCount = 1;
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
            moveArr(arr);
        }
    }
    return winner;
}

int getWinner_2(vector<int>& arr, int k) {
    int i = 0, winCount = 0;
    while(winCount < k && i < (int)arr.size()) {
        if(arr[i] > arr[i + 1]) {
            winCount++;
            arr[i + 1] = arr[i];
        } else {
            winCount = 1;
        }
        i++;
    }
    return arr[i];
}

int main() {
    vector<int> arr = {2, 1, 3, 5, 4, 6, 7};
    int k = 2;
    cout << getWinner_2(arr, k);
}