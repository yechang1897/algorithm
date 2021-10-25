#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValid(TreeNode* rightNode, TreeNode* leftNode) {
    if(rightNode -> right == NULL && leftNode -> left == NULL) {
        return true;
    }
    if (rightNode -> val > rightNode->right-> val) {
        return false;
    }
    if (leftNode -> val < leftNode -> left -> val) {
        return false;
    }
    return rightNode->right->val > leftNode->left->val ? isValid(rightNode->right, leftNode->left) && isValid(rightNode->left, leftNode->right) : false;
}

bool isValidBST(TreeNode* root) {
    return isValid(root -> right, root -> left);
}

bool isValidBST_2(TreeNode* root, long l = LONG_MIN, long r = LONG_MAX) {
    if(root == NULL) return true;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    if(root->val > l && root->val < r)
        return isValidBST_2(root->left, l, root->val) && isValidBST_2(root->right, root->val, r);
    return false;
}

int main() {
    // vector<int> values = {2, 1, 3};
    // TreeNode *root = new TreeNode();
    // root->val = values[0];
    // root->left->val = values[1];
    // root->left->left = NULL;
    // root->left->right = NULL;
    // root->right->val = values[2];
    // root->right->left = NULL;
    // root->right->right = NULL;
    // cout << isValidBST(root);
    // vector<int> nums;

    // int a, b, c, d, x;
    // a = c = 0;
    // b = 1;
    // d = 20;
    // if(a)
    //     d = d - 10;
    //     else if(!b)
    //         x = 15;
    //         else
    //             x = 25;
    //         printf("d=%d\n", d);
    // int x[10][100];
    // int *p = x[1];
    // printf("%d", sizeof(p));

    // int x = 0, y = 1, z = 0;
    // if(x=z=y) {
    //     x = 3;
    // }
    // int x = 3, y = 2;
    // float a = 2.5, b = 3.5;
    // // printf("%d", (x + y) % 2 + (int)a / (int)b);
    // char ch = 'A';
    // printf("%c", ch + 32);
    char *p,*q = "abc";
      printf("%s", q);
    char s[] = "abc";

    p = s;
    q = p;
    p[1] = 'B';
    printf("%s", q);
}
