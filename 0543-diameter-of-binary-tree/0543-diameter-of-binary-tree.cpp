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
    int depth(TreeNode* root,int &diameter)
    {
        if(root==NULL)
            return 0;
        int leftH=depth(root->left,diameter);
        int rightH=depth(root->right,diameter);
        diameter=max(leftH+rightH,diameter);
        return 1+max(leftH,rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        // return max(diameterOfBinaryTree(root->right),max(diameterOfBinaryTree(root->left),depth(root->left)+depth(root->right)));
        int diameter=0;
        int r=depth(root,diameter);
        return diameter;
    }
};