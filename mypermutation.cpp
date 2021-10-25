#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void permutation(vector<int>& num){
    int len = num.size();
    int i,j;
    for (i = len - 2; i >= 0; i--) {
        if(num[i] < num[i + 1]){
            break;
        }
    }
    for (j = len - 1; j > i; j--){
        if(num[i] < num[j]){
            swap(num[i], num[j]);
        }
    }
    reverse(num.begin() + i + 1, num.end());
    for_each(num.begin(), num.end(), [](int i) { cout << i; }), cout << endl;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> reverseVector = arr;
    reverse(reverseVector.begin(), reverseVector.end());
    // permutation(arr);
    // for_each(arr.begin(), arr.end(), [](int i) { cout << i; }), cout << endl;
    // permutation(arr);
    // permutation(arr);
    while(arr != reverseVector){
      permutation(arr);  
    }
}