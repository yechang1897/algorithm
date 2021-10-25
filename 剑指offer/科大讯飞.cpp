#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    string str;
    cin >> str;
    unordered_map<char, int> map;
    int l = 0, r = 0;
    int cnt = 0;
    int res = 0;
    while(r < str.size()) {
        if(str[r] == '?') cnt++;
        else {
            if(map.find(str[r]) != map.end()) map[str[r]] ++;
            else map[str[r]] = 1;
        }
       

        int sz = map.size();
        if(sz + cnt == 26) {
            while(map.size() + cnt == 26) {
                if(str[l] == '?') cnt--;
                else {
                    if(map[str[l]] == 1) {
                        res = max(res, r - l + 1);
                        break;
                    }
                    map[str[l]]--;
                }
                l++;
            }
        }

        r++;
    }
    cout << res << endl;
    return 0;
}