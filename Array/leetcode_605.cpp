#include<iostream>
#include<vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int sz = (int)flowerbed.size();
    int flag = 2;
    for(int i = 0; i < sz; i++) {
        if (flowerbed[i] == 1) {
            flag = 3;
        } else if(flowerbed[i] == 0){
            flag--;
            if(flag == 0) {
                flowerbed[i] = 1;
                n--;
                flag = 2;
            }
        }
        cout << flag << endl;
    }
    if (flowerbed[sz - 1] ==0 && flowerbed[sz - 2] == 0) {
        n--;
    }
    return n <= 0;
}

int main() {
    vector<int> flowerbed = {1,0,0,0,0};
    int n = 2;
    cout << canPlaceFlowers(flowerbed, n);
}