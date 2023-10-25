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
 int height(TreeNode* root){
     if(root == NULL){
         return 0;
     }
     if(root->left == NULL && root->right == NULL){
         return 1;
     }
     if(root->left == NULL){
         return 1+height(root->right);
     }
     if(root->right == NULL){
         return 1+height(root->left);
     }
     int left = height(root->left);
     int right = height(root->right);
     return min(left, right)+1;
 }
public:
    int minDepth(TreeNode* root) {
        return height(root);
    }
};