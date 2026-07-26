/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        int i = 0;
        for (auto it : inorder) {
            mp[it] = i++;
        }
        TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                                   postorder.size() - 1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
                        vector<int>& postorder, int postStart, int postEnd,
                        map<int, int>& mp) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;
        root->left = buildTree(inorder, inStart, inRoot - 1,postorder, postStart, postStart+ numLeft-1,mp);
        root->right = buildTree(inorder, inRoot + 1, inEnd,postorder, postStart + numLeft, postEnd-1,mp);
        return root;
    }
};