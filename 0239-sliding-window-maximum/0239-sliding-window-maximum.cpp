class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int start=0;
        int end=k-1;
        int n=nums.size();
        priority_queue<pair<int,int>>temp;
        vector<int>ans;
        // dequeue<int>temp;
        for(int i=0;i<k;i++)
        {
            temp.push({nums[i],i});
        }
        ans.push_back(temp.top().first);
        for(int i=k;i<n;i++)
        {
            temp.push({nums[i],i});
            while(temp.top().second<=i-k)
            {
                temp.pop();
            }
            ans.push_back(temp.top().first);
        }
        // int maxi=INT_MIN;
        // int maxi_ind=-1;
        // while(end<nums.size())
        // {
        //     for(int i=start;i<=end;i++)
        //     {

        //     }
        // }
        return ans;
    }
};