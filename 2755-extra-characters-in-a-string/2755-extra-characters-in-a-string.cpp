class Solution {
public:
    int helper(string s,int ind,unordered_map<string,int>temp,vector<int>&dp)
    {
        if(ind>=s.size())
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        string currStr="";
        int ans=INT_MAX;
        for(int i=ind;i<s.size();i++)
        {
            currStr+=s[i];
            int count=helper(s,i+1,temp,dp);
            if(temp.find(currStr)==temp.end())
            {
                count+=currStr.length();
            }
            ans=min(count,ans);
        }
        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_map<string,int>temp;
        for(auto it:dictionary)
        {
            temp[it]++;
        }
        vector<int>dp(s.length()+1,0);
        for(int ind=s.size()-1;ind>=0;ind--)
        {
            string currStr="";
            int ans=INT_MAX;
            for(int i=ind;i<s.size();i++)
            {
                currStr+=s[i];
                int count=dp[i+1];
                if(temp.find(currStr)==temp.end())
                {
                    count+=currStr.length();
                }
                ans=min(count,ans);
            }
            dp[ind] = ans;
        }
        return dp[0];
    }
};