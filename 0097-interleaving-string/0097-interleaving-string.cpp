class Solution {
public:
    bool helper(string s1,string s2,string s3,int ind1,int ind2,int ind3,int n,int m,int outlen,vector<vector<int>>&dp)
    {
        if(ind1==n && ind2==m)
        {
            if(ind3==outlen)
                return true;
        }
        int three=false;
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        if(ind1<n && ind2<m && ind3<outlen && s1[ind1]==s3[ind3] && s2[ind2]==s3[ind3])
        {
            three=helper(s1,s2,s3,ind1+1,ind2,ind3+1,n,m,outlen,dp)||helper(s1,s2,s3,ind1,ind2+1,ind3+1,n,m,outlen,dp);
        }
        else if(ind1<n && ind3<outlen && s1[ind1]==s3[ind3])
        {
            three=three||helper(s1,s2,s3,ind1+1,ind2,ind3+1,n,m,outlen,dp);
        }
        else if(ind2<m && ind3<outlen && s2[ind2]==s3[ind3])
        {
            three=three||helper(s1,s2,s3,ind1,ind2+1,ind3+1,n,m,outlen,dp);
        }
        return dp[ind1][ind2] = three;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n=s1.length();
        int m=s2.length();
        int outlen=s3.length();
        if(n+m!=outlen)
            return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return helper(s1,s2,s3,0,0,0,n,m,outlen,dp);
        dp[n][m]=1;
        for(int ind1=n;ind1>=0;ind1--)
        {
            for(int ind2=m;ind2>=0;ind2--)
            {
                // for(int ind3=outlen-1;ind3>=0;ind3--)
                // {
                    bool three=false;
                    if(ind1<n && ind2<m && (s1[ind1]==s3[ind1+ind2] && s2[ind2]==s3[ind2+ind1]))
                    {
                        three=dp[ind1+1][ind2]||dp[ind1][ind2+1];
                    }
                    else if(ind1<n && s1[ind1]==s3[ind2+ind1])
                    {
                        three=dp[ind1+1][ind2];
                    }
                    else if(ind2<m && s2[ind2]==s3[ind1+ind2])
                    {
                        three=dp[ind1][ind2+1];
                    }
                    dp[ind1][ind2] = dp[ind1][ind2]||three;
                // }
            }
        }
        return dp[0][0]==1;
    }
};