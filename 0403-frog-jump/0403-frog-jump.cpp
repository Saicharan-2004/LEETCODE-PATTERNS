class Solution {
public:
    bool helper(vector<int>s,int ind,int lastJump,vector<vector<long long>>&dp)
    {
        if(ind==s.size()-1)
        {
            return true;
        }
        bool ans=false;
        if(dp[ind][lastJump]!=-1)
        {
            return dp[ind][lastJump];
        }
        for(int i=ind+1;i<s.size();i++)
        {
            if(s[i]-s[ind]>(lastJump+1))
            {
                return dp[ind][lastJump]= ans;
            }
            if(s[i]-s[ind]==(lastJump))
            {
                ans=ans|(helper(s,i,lastJump,dp));
            }
            else if(s[i]-s[ind]==(lastJump+1))
            {
                ans=ans|(helper(s,i,lastJump+1,dp));
            }
            else if(s[i]-s[ind]==(lastJump-1))
            {
                ans=ans|(helper(s,i,lastJump-1,dp));
            }
        }
        return dp[ind][lastJump]= ans;

    }
    bool canCross(vector<int>& stones) 
    {
        vector<vector<long long>>dp(stones.size()+2,vector<long long>(stones.size()+2,-1));
        return helper(stones,0,0,dp);
    }
};