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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        queue<TreeNode*> help;
        help.push(root);
        while(!help.empty())
        {
            TreeNode*temp=help.front();
            help.pop();
            TreeNode*t=temp->left;
            temp->left=temp->right;
            temp->right=t;
            if(temp->left!=NULL)
            {
                help.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                help.push(temp->right);
            }
        }
        return root;
    }
};