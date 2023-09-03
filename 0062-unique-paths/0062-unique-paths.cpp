class Solution {
public:
int helper(int m,int n,vector<vector<int>>dp)
{
    if(m==0&&n==0)
    {
        return dp[m][n]=1;
    }
    if(m<0||n<0)
    {
        return 0;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    int left=helper(m,n-1,dp);
    int right=helper(m-1,n,dp);
    return dp[m][n]=left+right;
}
int uniquePaths(int m, int n) 
{
    vector<int>prev(n,0);
    for(int i=0;i<m;i++)
    {
        vector<int>curr(n,0);
        for(int j=0;j<n;j++)
        {
            if(i==0&&j==0)
            {
                curr[j]=1;
            }
            else
            {
                int left=0,top=0;
                if(i>0)
                    top=prev[j];
                if(j>0)
                    left=curr[j-1];
                curr[j]=left+top;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}
};