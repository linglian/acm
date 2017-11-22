#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
    }
};

TreeNode * insertNode(TreeNode * root, TreeNode * node) {
    // write your code here
    stack<TreeNode * > sta;
    sta.push(root);
    TreeNode * last = NULL;
    while (sta.size() != 0) {
        TreeNode * now = sta.top();
        sta.pop();
        if (now == NULL) {
            if (last == NULL) {
                root = node;
            } else if (last->val <= node->val) {
                last -> right = node;
            } else {
                last -> left = node;
            }
            break;
        } else if (now->val <= node->val) {
            sta.push(now->right);
        } else {
            sta.push(now->left);
        }
        last = now;
    }
    return root;
}

int main() {
    TreeNode * n = new TreeNode(1);
    TreeNode * root = insertNode(NULL, n);
    cout << root->val << endl;
    return 0;
}