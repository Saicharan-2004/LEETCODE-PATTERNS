class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int>temp;
        int n=nums.size();
        for(auto it:nums)
            temp[it]++;
        for(auto it:temp)
        {
            if(it.second>n/2)
            {
                return it.first;
            }
        }
        return -1;
    }
};