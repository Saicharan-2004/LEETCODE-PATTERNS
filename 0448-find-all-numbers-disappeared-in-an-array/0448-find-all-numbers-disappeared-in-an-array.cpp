class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans;
        for(auto it:nums)
        {
            while(nums[it-1]!=it)
            {
                swap(it,nums[it-1]);
            }
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(i!=nums[i-1])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};