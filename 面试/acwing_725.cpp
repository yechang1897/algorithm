#include<iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int nums[N];
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for(int i = 0; i < N; i++) {

        int res = 0;
        for(int j = 1; j * j < nums[i]; j++) {
            if(nums[i] % j == 0) {
                res += j;
                if(nums[i] / j != j && nums[i] / j != nums[i]) res += nums[i] / j;
            }

        }
        if(res == nums[i]) cout << nums[i] << " is perfect" << endl;
        else cout << nums[i] << " is not perfect" << endl;
    }
}