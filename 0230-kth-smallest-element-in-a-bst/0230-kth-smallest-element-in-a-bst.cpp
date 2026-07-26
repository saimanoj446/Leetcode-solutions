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
    int ans=-1;
    void kthSmall(TreeNode* root, int k,int &cnt){
        //inorder: left, node, root
        if(!root) return;
        kthSmall(root->left,k,cnt);
        cnt++;
        if(cnt==k) {
            ans= root->val;
            return;
        }
        if(cnt<k){
            kthSmall(root->right,k,cnt);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        kthSmall(root,k,cnt);
        return ans;
    }
};