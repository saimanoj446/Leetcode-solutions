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
    bool path(TreeNode* root,int k,int &sum){
        if(!root) return false;
        sum+=root->val;
        if(sum==k && (!root->right && !root->left)) return true;
        else{
            if(path(root->right,k,sum)||path(root->left,k,sum)) return true;
        }
        sum-=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return path(root,targetSum,sum);
    }
};