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
    // Right-side view, or find the last node at each level (Level-order traversal) 
    vector<int> rightSideView(TreeNode* root) {
        vector<int> RSV; 
        if (!root)
            return RSV;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()){
            //add size of the level
            int size = que.size();
            
            // For each node in the level, pop it from the queue, if it's the last in the level then add it to RSV vector
            // Then add its children nodes, 
            for (int i =0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                // if node is the last node in the level, push it to right-side view (RSV) vector 
                if (i == size - 1)
                    RSV.push_back(cur->val);
                
                //add the children nodes of this node to the queue
                if (cur->left != nullptr)
                    que.push(cur->left);
                if (cur->right != nullptr)
                    que.push(cur->right);

            }
        }
        return RSV;
    }
};