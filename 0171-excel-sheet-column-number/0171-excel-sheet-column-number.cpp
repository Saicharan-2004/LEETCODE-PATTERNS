class Solution {
public:
    int titleToNumber(string s) 
    {
        int ans=0;
        reverse(s.begin(),s.end());
        int n=s.length();
        int t=0;
        for(int i=0;i<n;i++)
        {
            ans+=pow(26,t)*(s[i]-'A'+1);
            t++;
        }
        return ans;
    }
};