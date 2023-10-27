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
  int findPosition(vector<int>& inorder ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(inorder[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& preorder, int n, int&index, int inorderStart, int inorderEnd){
        if(index>=n || inorderStart> inorderEnd){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos  = findPosition(inorder , inorderStart , inorderEnd ,element, n);
        root->left = helper(inorder,preorder,n,index,inorderStart, pos-1);
        root->right = helper(inorder,preorder,n,index,pos+1,inorderEnd);
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderindex =0;
        int n = inorder.size();
        TreeNode* ans = helper(inorder,preorder,n, preOrderindex, 0, n-1);
        return ans;
    }
};