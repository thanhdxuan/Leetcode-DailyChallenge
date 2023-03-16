/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int np = postorder.size();
        if (np == 0) return nullptr;
        if (np == 1) return new TreeNode(postorder[0]);
        int root = postorder[np - 1];
        vector<int> inleft;
        vector<int> inright;
        vector<int> pleft, pright;
        bool saw = false;
        for (auto &x : inorder) {
            if (x != root && !saw) inleft.push_back(x);
            else if (x != root && saw) inright.push_back(x);
            else {
                saw = true;
            }
        }
        for (int i = 0; i < np - 1; i++) {
            if (i < int(inleft.size())) pleft.push_back(postorder[i]);
            else pright.push_back(postorder[i]);
        }
        TreeNode* node = new TreeNode(root);
        node->left = buildTree(inleft, pleft);
        node->right = buildTree(inright, pright);
        return node;
    }
};
/*
Inorder: LNR
inorder[] == root;
[9,|3|,15,|20|,7]
I: [1,2,4,10,11,12]
P: [1,4,2,12,11,10]
L: 1,2,4
R: 11,12
N: 10

L: 1,4,2
R: 12,11
postorder[-1] = root;
[9,15,7,20,|3]

Postorder: LRN

*/
