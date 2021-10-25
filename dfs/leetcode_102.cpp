#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<pair<int,TreeNode*>> q;
        map<int,vector<int>> m;
        vector<vector<int>> res;
        q.push({0,root});
        while(!q.empty()) {
            TreeNode* node = q.front().second;
            int level = q.front().first;
            q.pop();
            m[level].push_back(node->val);
            if(node->left) {
                q.push({level + 1,node->left});
            }
            if(node->right) {
                q.push({level + 1,node->right});
            }
        }
        for(auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
}

int main() {

}