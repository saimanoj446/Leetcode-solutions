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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        vector<int> temp;
        int flag=1;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                temp.push_back(node->val);
            }
            if(flag==1){
                flag=0;
            }
            else{
                reverse(temp.begin(),temp.end());
                flag=1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};