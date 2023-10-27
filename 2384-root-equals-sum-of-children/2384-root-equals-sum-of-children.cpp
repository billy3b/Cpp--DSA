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
private:
    pair<bool, int> checkTreeFast(TreeNode* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true,0);
        }
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = make_pair(true, root->val);
            return p;
        }
        pair<bool, int> leftAns = checkTreeFast(root->left);
        pair<bool, int> rightAns = checkTreeFast(root->right);

        bool sum = root->val == leftAns.second+rightAns.second;

        pair<bool, int> ans;

        if(sum && leftAns.first && rightAns.first){
            ans.first = true;
            ans.second = 2*root->val;
        } else{
            ans.first  = false;
        }
        return ans;
    }
public:
    bool checkTree(TreeNode* root) {
        return checkTreeFast(root).first;
    }
};