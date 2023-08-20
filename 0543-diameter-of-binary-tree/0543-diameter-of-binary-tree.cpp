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
    int depth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        return max(diameterOfBinaryTree(root->right),max(diameterOfBinaryTree(root->left),depth(root->left)+depth(root->right)));
    }
};