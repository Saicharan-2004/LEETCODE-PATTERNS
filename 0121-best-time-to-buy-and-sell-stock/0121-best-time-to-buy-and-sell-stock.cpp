class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int n=arr.size();
        int mini=arr[0];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,arr[i]);
            ans=max(ans,arr[i]-mini);
        }
        return ans;
    }
};