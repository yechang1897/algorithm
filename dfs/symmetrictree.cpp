#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root) {
    isMirrow(root->left, root->right);
}

bool isMirrow(TreeNode* left, TreeNode* right) {
    if(left->left == NULL && right->right == NULL) {
        return true;
    } else if (left->left == NULL || right->right != NULL) {
        return false;
    }
    return left->val == right->val ? isMirrow(left->left, right->right) && isMirrow(left->right,right->left) : false;
}

int main() {

}