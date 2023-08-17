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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {0};
        }
        queue<TreeNode*>temp;
        temp.push(root);temp.push(NULL);
        vector<double>ans;
        double sum=0;double count=0;
        while(!temp.empty())
        {
            TreeNode*curr=temp.front();
            temp.pop();
            if(curr==NULL)
            {
                if(temp.empty())
                {
                    ans.push_back(sum/count);
                    return ans;
                }
                else
                {
                    if(count!=0)
                    {
                        double r=(sum/count);
                        ans.push_back(r);
                    }
                    temp.push(NULL);
                    sum=0;
                    count=0;
                }
            }
            else
            {
                sum+=curr->val;
                count++;
                if(curr->left)
                {
                    temp.push(curr->left);
                }
                if(curr->right)
                {
                    temp.push(curr->right);
                }
            }
            // TreeNode*front=temp.front();
            // temp.pop();
            // if(front==NULL)
            // {
            //     temp.push(NULL);
            //     ans.push_back(sum/count);
            //     sum=0;
            //     count=0;
            // }
            // else
            // {
            //     if(root->left)
            //     {
            //         temp.push(root->left);
            //     }
            //     if(root->right)
            //     {
            //         temp.push(root->right);
            //     }
            //     sum+=front->val;
            //     count++;
            // }
        }
        return ans;
    }
};