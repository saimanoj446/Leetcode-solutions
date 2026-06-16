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
    bool isLeaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }
    void path(TreeNode* root, string temp,vector<string>& ans){
        if(!root) return;
        if(temp.empty()){
            temp+=to_string(root->val);
        }
        else temp+="->"+to_string(root->val);
        if(isLeaf(root)) ans.push_back(temp);
        path(root->left,temp,ans);
        path(root->right,temp,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        if(root==NULL) return ans;
        path(root,temp,ans);
        return ans;
    }
};