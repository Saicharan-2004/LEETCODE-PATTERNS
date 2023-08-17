class Solution {
public:
    // int helper(vector<vector<int>>&matrix,int m,int n,int i,int j)
    // {
    //     if(i==m-1&&j==n-1)
    //     {

    //     }
    // }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        // return helper(mat,m,n,0,0);
        int n=mat.size();
        int m=mat[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]!=0)
                {
                    int ans=1e5;
                    if(i-1>=0)
                    {
                        ans=min(ans,mat[i-1][j]);
                    }
                    if(j-1>=0)
                    {
                        ans=min(ans,mat[i][j-1]);
                    }
                    mat[i][j]=ans+1;
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j]!=0)
                {
                    int ans=1e5;
                    if(i+1<n)
                    {
                        ans=min(ans,mat[i+1][j]);
                    }
                    if(j+1<m)
                    {
                        ans=min(ans,mat[i][j+1]);
                    }
                    mat[i][j]=min(mat[i][j],ans+1);
                }
            }
        }
        return mat;
    }
};