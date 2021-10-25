#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

string destCity(vector<vector<string>>& paths) {
    unordered_map<string,int> citys;
    for(int i = 0 ; i < (int)paths.size(); ++i) {
        for (int j = 0; j <(int) paths[0].size(); ++j) {
            if (citys.find(paths[i][j]) == citys.end()) {
                citys[paths[i][j]] = 1;
            } else {
                citys[paths[i][j]]++;
            }
        }
    }
    string res;
    for (int i = 0; i < (int)paths.size(); ++i) {
        if(citys[paths[i][1]] == 1) {
            res = paths[i][1];
        }
    }
    return res;
}

int main() {
    vector<vector<string>> paths = {{"B","C"},{"D","B"},{"C","A"}};
    cout << destCity(paths);
}
