#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int nums[4] = {2, 1, 3, 1};

    int f[4][4];
    memset(f, 0, sizeof f);
    
    for(int i = 0; i < 4; i++) if(nums[i] == 0) f[i][i] = 1;

    for(int len = 2; len <= 4; len++) {
        for(int i = 0; i < 4 - len + 1; i++) {
            int j = i + len - 1;
            
            if(len == 2) {
                if((nums[i] & nums[j]) == 0) {
                    f[i][j] = 1;
                }
            } else {
                cout << i << " " << j << endl;
                if(f[i][j - 1] != 0 && (nums[j] & 0) == 0)
                    f[i][j] += f[i][j - 1] + 1;

                if(f[i + 1][j] != 0)
                    f[i][j] += f[i + 1][j];    
            }          
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << f[0][3] << endl;
    return 0;    
}