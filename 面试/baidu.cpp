#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> maxActors(vector<int> ft, vector<int> at) {
    unordered_map<int, int> m;
    for(int i = 0; i < at.size(); i++) {
        if(m.find(at[i]) == m.end()) {
            m[at[i]] = i;
        }
    }
    sort(at.begin(), at.end());
    for(int i = 0; i < ft.size(); i++) {
        for(int j = 0; j < at.size(); j++) {
            if(ft[i] < at[j]) {
                res.push_back(j + 1);
            } else {

            }
        }
    }
}


// vector<int> temp;
// void dfs(TreeNode * root, int target) {
//     if(!root) {
//         return;
//     }
//     if(root->val == target) {
//         return;
//     }
//     temp.push_back(root->val);
//     dfs(root->left);
//     dfs(root->right);
//     temp.pop_back(root->val);
// }

int minStep(int N) {
    vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 1; i < N; ++i) {
        dp[i + 1] = min(dp[i + 1],dp[i]) + 1;
        if(i * 2 < N) {
            dp[i * 2] = dp[i] + 1;
        }
        if(i * 3 < N) {
            dp[i * 3] = dp[i] + 1;
        } 
    }
    for(int i : dp) {
        cout << i << " ";
    }
    cout << endl;
    return dp[N];
}

vector<string> solution(Node node) {
    if(node == null) {
        return nullptr;
    }
    unordered_map<int, string> map;
    pre(node,map, 1);
    vector<string> res;
    for(pair<int, string> p : map) {
        res.push_back(p.second);
    }
    return res;
}

void pre(Node node, unordered_map<int, string> map, int level) {
    if(node == null) {
        return;
    }

    if(map.find(level) != map.end()) {
        map.put(level,node->val);
    }
    pre(node->left, map, level + 1);
    pre(node->right, map, level + 1);
}

void reverse()

int main() {
    // int N;
    // cin >> N;
    // int f, t;
    // cin >> f >> t;
    // vector<int> ft(f);
    // vector<int> at(t);
    // for(int i = 0; i < f; ++i) {
    //     cin >> ft[i];
    // }
    // for(int i = 0; i < f; ++i) {
    //     cin >> at[i];
    // }
    cout << minStep(10);
}