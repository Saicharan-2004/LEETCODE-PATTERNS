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
    bool helper(TreeNode*root,TreeNode*searcher)
    {
        if(root==NULL && searcher==NULL)
        {
            return true;
        }
        if(!root || !searcher)
        {
            return false;
        }
        return (root->val==searcher->val)&&(helper(root->left,searcher->left)&&helper(root->right,searcher->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL)
        {
            return false;
        }
        return helper(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};