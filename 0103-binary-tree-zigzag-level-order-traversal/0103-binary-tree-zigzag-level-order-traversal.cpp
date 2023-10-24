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
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool reverseOrder = false;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelNodes;
            stack<int> reverseStack;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                if (reverseOrder) {
                    reverseStack.push(currentNode->val);
                } else {
                    levelNodes.push_back(currentNode->val);
                }

                if (currentNode->left) {
                    q.push(currentNode->left);
                }

                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }

            while (!reverseStack.empty()) {
                levelNodes.push_back(reverseStack.top());
                reverseStack.pop();
            }

            res.push_back(levelNodes);
            reverseOrder = !reverseOrder;
        }

        return res;
    }
};