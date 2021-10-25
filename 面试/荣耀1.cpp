#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> words(26, 0);
    vector<int> nums(10, 0);
    vector<int> pos;
    for (int i = 0; i < str.size(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            int idx = str[i] - '0';
            nums[idx]++;
            pos.push_back(i);
        } else {
            int idx = str[i] - 'a';
            words[idx]++;
        }
    }
    int flag = 0;
    int flag2 = 0;
    int flag3 = 0;
    for (int i = 0; i < str.size(); i++) {
        if(pos[flag] == i) {
            while(!nums[flag2]) {
                flag2++;
            }
            str[i] = flag2 + '0';
            nums[flag2]--;
            flag++;
        } else {
            while(!words[flag3] ) {
                flag3++;
            }
            str[i] = flag3 + 'a';
            words[flag3]--;
        }
    }
    cout << str << endl;
    return 0;
}