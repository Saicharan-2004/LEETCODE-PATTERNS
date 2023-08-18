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
    int helper(TreeNode*root)
    {
        if(root==NULL)
        {
            return 1e9;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            return 1;
        }
        return 1+min(helper(root->right),helper(root->left));
    }
    int minDepth(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int d=1;
        while(!q.empty())
        {
            TreeNode*front=q.front();
            q.pop();
            if(front==NULL)
            {
                if(q.empty())
                {
                    return d;
                }
                else
                {
                    d++;
                    q.push(NULL);
                }
            }
            else
            {
                if(front->left==NULL&&front->right==NULL)
                {
                    return d;
                }
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
        }
        return d;
    }
};