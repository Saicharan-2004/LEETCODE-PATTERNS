class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        // int start=0;
        // int end=k-1;
        int n=nums.size();
        // priority_queue<pair<int,int>>temp;
        vector<int>ans;
        deque<int>temp;
        for(int i=0;i<n;i++)
        {
            if(i-temp.front()==k)
            {
                temp.pop_front();
            }
            while(!temp.empty() && nums[temp.back()]<=nums[i])
            {
                temp.pop_back();
            }
            temp.push_back(i);
            if(i>=k-1)
            {
                ans.push_back(nums[temp.front()]);
            }
        }
        // // dequeue<int>temp;
        // for(int i=0;i<k;i++)
        // {
        //     temp.push({nums[i],i});
        // }
        // ans.push_back(temp.top().first);
        // for(int i=k;i<n;i++)
        // {
        //     temp.push({nums[i],i});
        //     while(temp.top().second<=i-k)
        //     {
        //         temp.pop();
        //     }
        //     ans.push_back(temp.top().first);
        // }

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