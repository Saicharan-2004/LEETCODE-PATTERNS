class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_set<int>temp(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(temp.find(i+1)==temp.end())
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};