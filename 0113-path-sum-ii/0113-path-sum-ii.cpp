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
    void path(TreeNode* root,int k,vector<int> temp,int sum, vector<vector<int>> &ans){
        if(!root) return;
        temp.push_back(root->val);
        sum+=root->val;
        if(sum==k && (!root->left && !root->right)){
            ans.push_back(temp);
        }
        path(root->left,k,temp,sum,ans);
        path(root->right,k,temp,sum,ans);
        temp.pop_back();
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum=0;
        vector<int> temp;
        path(root,targetSum,temp,sum,ans);
        return ans;
    }
};