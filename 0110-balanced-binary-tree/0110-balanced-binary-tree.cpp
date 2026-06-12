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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int rs=maxDepth(root->right);
        int ls=maxDepth(root->left);
        return 1+max(rs,ls);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(abs(maxDepth(root->left)-maxDepth(root->right))>1) return false;
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(left && right) return true;
        return false;
    }
};